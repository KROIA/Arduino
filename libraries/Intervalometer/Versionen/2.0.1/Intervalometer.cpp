
/*Intervalometer
Author 			: Alex Krieg
Version			: 2.0.1		
compatibility 	: Hardware 1.0.0s
Date			: 6.3.2016

copyright by BlenderEr Informatics®
All rights reserved
*/


#include "Intervalometer.h"


 Intervalometer::Intervalometer(int bOK,int bUp,int bDown,int blUp,int blDown,int bback,boolean logicLevel,int shuter,int focus,int display,int light,int LDR)
{
	p_lcd 					= new LiquidCrystal_I2C(0x20,16,2);
	p_buttonLightUp  		= new Button(blUp,		logicLevel);
	p_buttonLightDown		= new Button(blDown,	logicLevel);
	p_buttonUp            	= new Button(bUp,		logicLevel);
	p_buttonDown          	= new Button(bDown, 	logicLevel);
	p_buttonOk            	= new Button(bOK,		logicLevel);
	p_buttonBack			= new Button(bback,		logicLevel);
	p_led	 				= new Led(13);
	
	
	focusPin				= focus;
	ldrPin					= LDR;
	shuterPin				= shuter;
	displayPin				= display;
	brightnessPin			= light;
	
	
	mode 						= 	Hauptmenue;
	MenueMode					= 	HauptmenueAuswahl_1;
	lastMenueMode				= 	HauptmenueAuswahl_1;
	
	unterModeInterval			= 	IntervalSetzen;
	unterModeBlitz				= 	ToleranzSetzen;
	unterModeZeitAusloeser		=	ZeitAusloeserSetup;
	unterModeSerienAufnahme		= 	SerieSetAmount;
	
	lastUnterModeInterval		= 	IntervalSetzen;
	lastUnterModeBlitz			=	ToleranzSetzen;
	lastUnterModeZeitAusloeser	=	ZeitAusloeserSetup;
	lastUnterModeSerienAufnahme	=	SerieSetAmount;
	
	
	light 			= 0;
	setFocus		= true;
	SerienAufnahmeIsRunning = false;
	timeIsRunning	= false;
	displayStat		= true;
	timeToShoot 	= 1000;		//in ms
	shootTime       = 0;
	passedTime		= 0;
	minuten 		= 0;
	stunden 		= 0;
	images			= 0;
	lastTime		= 60;
	lastMode		= 0;
	lastIntervall	= 5;
	referenceTime   = 0;
	
	countDown		= 10;
	fastStart		= false;
	
	currentMillis   = 0;
	previousMillis  = 0;
	previousMillis2	= 0;
	
	toleranz 		= 100;
	takt 			= 5;
	
	ldrValue		= 0;
	lastLdrValue	= 0;
	
	
	
	SerieInterval		= 500;		//ms
	SeriePictures		= 5;
	deactivate			= false;
}

 Intervalometer::~Intervalometer()
{
	delete p_lcd; 					
	delete p_buttonLightUp;  	
	delete p_buttonLightDown;	
	delete p_buttonUp;            	
	delete p_buttonDown;          	
	delete p_buttonOk;  
	delete p_buttonBack;	
	delete p_led;					
}

void Intervalometer::init()
{
	Serial.begin(9600);
    while(!Serial){}
	
	pinMode       (shuterPin,OUTPUT);
	pinMode		  (focusPin,OUTPUT);
	pinMode       (displayPin,OUTPUT);
	pinMode		  (brightnessPin, OUTPUT);
	digitalWrite  (shuterPin,LOW);
	digitalWrite  (displayPin,HIGH);
  
  
	p_lcd-> 					init();
	p_buttonLightUp->  			init();
	p_buttonLightDown->			init();
	p_buttonUp->            	init();
	p_buttonDown->          	init();
	p_buttonOk->            	init();
	p_buttonBack->			 	init();
	p_led->				     	init();
	p_lcd->     createChar(2, kamera);
	p_lcd -> 	createChar(1,PfeilDown);
	p_lcd -> 	createChar(0,PfeilUp);
	
	setLight();
	intro();
	p_lcd->clear();
	
	//Serial.println("SETUP DONE");	
}

void Intervalometer::run()
{
	checkButtons();
	currentMillis = millis();
	switch(mode)
	{
		case IntervalMode:
		{
			switch(unterModeInterval)
			{
				case IntervalSetzen:
					{
						// Anzeige Display aktualisiern
						p_lcd->                         setCursor  (0, 0);
						p_lcd->                         print      ("Interval:            ");
						p_lcd->                         setCursor  (0, 1);
						if ((lastIntervall/10) < 10)     
						p_lcd->                         print      ("0");
						p_lcd->                         print      (lastIntervall/10);
						p_lcd->                         print      (" ");
						p_lcd->                         setCursor  (7, 1);
						p_lcd->                         print      ("Sekunden             ");
					break;
					}
				case AufnahmezeitSetzen:
					{
						// Anzeige Display aktualisieren
						
						stunden                  = lastTime / 3600 %60;
						minuten                  = lastTime / 60 % 60 ;
						Serial.println(lastTime);
						p_lcd                    ->setCursor  (0, 0);
						p_lcd                    ->print      ("Aufnahmezeit:           ");
						p_lcd                    ->setCursor  (0, 1);
						if (stunden < 10)        
						p_lcd                    ->print      ("0");
						p_lcd                    ->print      (stunden);
						p_lcd                    ->print      (":");
						if (minuten < 10)        
						p_lcd                    ->print      ("0");
						p_lcd                    ->print      (minuten);
						p_lcd                    ->setCursor  (5, 1);
						p_lcd                    ->print      ("  Stunden               ");
					break;
					}
				case KontrolleInterval:
					{

						// Anzeige Display aktualisieren
					   p_lcd->                  setCursor    (0, 0);
					   p_lcd->                  print        (" ");
					   p_lcd->                  print        ("    Interval:     ");
					   if((lastIntervall/10)<10)  
					   p_lcd->                  print        ("0");
					   p_lcd->                  print        (lastIntervall/10);
					   p_lcd->                  print        (" Sekunden      ");
					   p_lcd->                  setCursor    (0, 1);
					   p_lcd->                  print        ("     Aufnahmezeit: ");
					   if(stunden<10)           
					   p_lcd->                  print        ("0");
					   p_lcd->                  print        (stunden);
					   p_lcd->                  print        (":");
					   if(minuten < 10)        
					   p_lcd->                  print        ("0");
					   p_lcd->                  print        (minuten);
					   p_lcd->                  print        (" Stunden              ");
					   
					   if(currentMillis - previousMillis > scrollTimer)
					  {
					   previousMillis = currentMillis;

					   p_lcd->                  scrollDisplayLeft();
					  }
					
					break;
					}	
				case IntervalRun:
					{
						passedTime = currentMillis - referenceTime;
						if (passedTime > shootTime*1000)
						{
							mode = AbschlussInfoInterval;
							stopRunning();
						}
						if(currentMillis - previousMillis > (lastIntervall*100)-200 && setFocus == true)
						{
							setFocus = false;
							//previousMillis2 =  currentMillis;
							Serial.println("focusON");
							digitalWrite(focusPin,HIGH);		//focusPin
						}
						if(currentMillis - previousMillis > lastIntervall*100)
						{
							setFocus = true;
							previousMillis =  currentMillis;
							Serial.println("shoot");
							shoot();
							digitalWrite(focusPin,LOW);		//focusPin
							Serial.println("focusOFF");
						}
					break;
					}
				case AbschlussInfoInterval:
					{
						int zSEC = passedTime%1000;
						int SEC = passedTime /1000 % 60;
						int MIN = passedTime / 60000 % 60;
						int STD = passedTime / 3600000 % 60;
						
						p_lcd->      print        ("Bilder: ");
						p_lcd->      print        (images);
						p_lcd->      setCursor    (0, 1);
						p_lcd->      print        ("Zeit:");
						if (STD < 10)
						p_lcd->      print        ("0");
						p_lcd->      print        (STD);
						p_lcd->      print        (":");
						if (MIN < 10)
						p_lcd->      print        ("0");
						p_lcd->      print        (MIN);
						p_lcd->      print        (":");
						if (SEC < 10)
						p_lcd->      print        ("0");
						p_lcd->      print        (SEC);
						p_lcd->      print        (":");
						if (zSEC < 10)
						p_lcd->      print        ("0");
						p_lcd->      print        (zSEC);
						p_lcd->      print        ("  ");
						break;
						}	
										
			}
		break;
		}
		case HelligkeitSetzenMode:
		{

			// Anzeige Display aktualisieren
		  p_lcd->                   setCursor    (0, 0);
		  p_lcd->                   print        ("Helligkeit: ");
		  p_lcd->                   setCursor    (0, 1);
		  p_lcd->                   print        (256-light);
		  p_lcd->                   print        ("  ");
		  p_lcd->                   setCursor    (5, 1);
		  p_lcd->                   print        ("/256       ");
		  
		  //setLight();
		break;
		}
		case Hauptmenue:
		{
			switch(MenueMode)
			{
				case HauptmenueAuswahl_1:	
				{
					p_lcd->                  setCursor    (0, 0);
					p_lcd->	print("Zeitraffer: OK");
					p_lcd->                  setCursor    (15, 0);
					p_lcd->	write(0);
					p_lcd->                  setCursor    (15, 1);
					p_lcd->	write(1);
					
					break;
				}
				case HauptmenueAuswahl_2:	
				{
					p_lcd->                  setCursor    (0, 0);
					p_lcd->	print("Blitz-: OK");
					p_lcd->                  setCursor    (15, 0);
					p_lcd->	write(0);
					p_lcd->                  setCursor    (0, 1);
					p_lcd->	print("ausloeser");
					p_lcd->                  setCursor    (15, 1);
					p_lcd->	write(1);
					break;
				}
				case HauptmenueAuswahl_3:	
				{
					p_lcd->                  setCursor    (0, 0);
					p_lcd->	print("PushTo-: OK");
					p_lcd->                  setCursor    (15, 0);
					p_lcd->	write(0);
					p_lcd->                  setCursor    (0, 1);
					p_lcd->	print("shoot");
					p_lcd->                  setCursor    (15, 1);
					p_lcd->	write(1);
					break;
				}
				case HauptmenueAuswahl_4:
				{
					p_lcd->                  setCursor    (0, 0);
					p_lcd->	print("Zeit-: OK ");
					p_lcd->                  setCursor    (15, 0);
					p_lcd->	write(0);
					p_lcd->                  setCursor    (0, 1);
					p_lcd->	print("ausloeser");
					p_lcd->                  setCursor    (15, 1);
					p_lcd->	write(1);
					break;
				}
				case HauptmenueAuswahl_5:
				{
					p_lcd->                  setCursor    (0, 0);
					p_lcd->	print("Serie-: OK");
					p_lcd->                  setCursor    (15, 0);	
					p_lcd->	write(0);
					p_lcd->                  setCursor    (0, 1);
					p_lcd->	print("aufnahme");
					p_lcd->                  setCursor    (15, 1);
					p_lcd->	write(1);
					break;
				}
			}
			
			
		break;
		}
		case BlitzMode:
		{
			switch(unterModeBlitz)
			{
				case ToleranzSetzen:
				{
					p_lcd->                  setCursor    (0, 0);
					p_lcd->	print("Toleranz von LDR:         ");
					p_lcd->                  setCursor    (0, 1);
					if(toleranz<1000)
						p_lcd-> print("0");
					if(toleranz<100)
						p_lcd-> print("0");
					if(toleranz<10)
						p_lcd-> print("0");
					p_lcd-> print(toleranz);
				break;
				}		 
				case TaktSetzen:
				{
					p_lcd->                  setCursor    (0, 0);
					p_lcd->	print("Takt:");
					p_lcd->                  setCursor    (0, 1);
					if(takt<1000)
						p_lcd-> print("0");
					if(takt<100)
						p_lcd-> print("0");
					if(takt<10)
						p_lcd-> print("0");
					p_lcd-> print(takt);
					p_lcd-> print(" in Ms");
				break;
				}
				case KontrolleBlitz:
				{
					p_lcd->                  setCursor    (0, 0);
					p_lcd->                  print        (" ");
					p_lcd->                  print        ("    Toleranz: ");
					if(toleranz<1000)
					p_lcd-> 			print("0");
					if(toleranz<100)
					p_lcd-> 			print("0");
					if(toleranz<10)
					p_lcd-> 			print("0");
					p_lcd->                  print(toleranz);
					p_lcd->                  print("      ");
					p_lcd->                  setCursor(0, 1);
					p_lcd->                  print("     Takt:     ");
					if(takt<1000)
					p_lcd-> 			print("0");
					if(takt<100)	
					p_lcd-> 			print("0");
					if(takt<10)	
					p_lcd-> 			print("0");
					p_lcd-> 			print(takt);
					p_lcd->                  print("         ");
				   
				   if(currentMillis - previousMillis > scrollTimer)
				  {
				   previousMillis = currentMillis;

				   p_lcd->                  scrollDisplayLeft();
				  }
				break;
				}
				case BlitzRun:
				{
					passedTime = currentMillis - referenceTime;
					if(currentMillis - previousMillis > takt)
					{
						previousMillis = currentMillis;
						ldrValue = analogRead(ldrPin);
						//digitalWrite(focusPin,HIGH);		//focusPin
						if((ldrValue-lastLdrValue) > toleranz)
						{
							shoot();
						}
						lastLdrValue = ldrValue;
					}
				break;
				}
				case AbschlussinfoBlitz:
				{
					int zSEC = passedTime%1000;
					int SEC = passedTime/1000 % 60;
					int MIN = passedTime / 60000 % 60;
					int STD = passedTime / 3600000 % 60;

					p_lcd->      print        ("Bilder: ");
					p_lcd->      print        (images);
					p_lcd->      setCursor    (0, 1);
					p_lcd->      print        ("Zeit:");
					if (STD < 10)
					p_lcd->      print        ("0");
					p_lcd->      print        (STD);
					p_lcd->      print        (":");
					if (MIN < 10)
					p_lcd->      print        ("0");
					p_lcd->      print        (MIN);
					p_lcd->      print        (":");
					if (SEC < 10)
					p_lcd->      print        ("0");
					p_lcd->      print        (SEC);
					p_lcd->      print        (":");
					if (zSEC < 10)
					p_lcd->      print        ("0");
					p_lcd->      print        (zSEC);
					p_lcd->      print        ("  ");
					break;
					}
			}
			break;
		}
		case countdown:
		{
				if(fastStart == true)
				{
					countDown = 0;
					fastStart = false;
				}
				referenceTime = currentMillis;
				if((countDown==0 && lastMode == SerienAufnahmeMode))
				{
					countDown = 10;
					//displayOff();
					digitalWrite(focusPin,HIGH);		//focus
					lastUnterModeSerienAufnahme = SerieSetInterval;
					unterModeSerienAufnahme = SerieRun;
					mode = lastMode;
				}
				if((countDown==0 && lastMode == IntervalMode))
				{  
					countDown = 10;
					displayOff();
					digitalWrite(focusPin,HIGH);		//focus
					//lastMode = mode;
					mode = lastMode;
					unterModeInterval = IntervalRun;
					
				}
				
				if((countDown==0 && lastMode == BlitzMode))
				{  
					countDown = 10;
					displayOff();
					digitalWrite(focusPin,HIGH);		//focus
					//lastMode = mode;
					mode = lastMode;
					ldrValue = analogRead(ldrPin);
					lastLdrValue = ldrValue;
					unterModeBlitz	=	BlitzRun;
				}
				if((currentMillis - previousMillis > 1000) && (countDown>0))
				{
					previousMillis =  currentMillis;
					{
						countDown--;
						p_lcd->              setCursor        (0,0);
						p_lcd->              print            ("Start in:");
						if(countDown<10)
						p_lcd->              print            ("0");
						p_lcd->              print            (countDown);
						p_lcd->              setCursor        (0,1);
						p_lcd->              print            ("Sekunden");
					}
				}				
				
				
		break;
		}
		case PushToShootMode:
		{
			if(displayStat == true)
			{
				p_lcd->      setCursor        (0,0);
				p_lcd->      print        ("OK to shoot");
				p_lcd->      setCursor        (0,1);
				p_lcd->      print        ("Bilder: ");
				p_lcd->      print        (images);
			}
			break;
		}
		case ZeitAusloeserMode:
		{
			
			switch(unterModeZeitAusloeser)
			{
				case ZeitAusloeserSetup:
				{
					int zSEC = timeToShoot%1000;
					int SEC = timeToShoot/1000 % 60;
					int MIN = timeToShoot / 60000 % 60;
					int STD = timeToShoot / 3600000 % 60;
					
					p_lcd->              setCursor        (0,0);
					p_lcd->      print        ("Zeit:");
					if (STD < 10)
					p_lcd->      print        ("0");
					p_lcd->      print        (STD);
					p_lcd->      print        (":");
					if (MIN < 10)
					p_lcd->      print        ("0");
					p_lcd->      print        (MIN);
					p_lcd->      print        (":");
					if (SEC < 10)
					p_lcd->      print        ("0");
					p_lcd->      print        (SEC);
					p_lcd->      print        (":");
					if (zSEC < 10)
					p_lcd->      print        ("0");
					p_lcd->      print        (zSEC);
					p_lcd->      print        ("  ");
		
					p_lcd->              setCursor        (0,1);
					p_lcd->      print        ("STD MIN SEC zSEC");
		
		
		
					break;
				}
				case ZeitAusloeserRun:
				{
					if(timeIsRunning == true)
					{
						displayOff();
						
						if(currentMillis - previousMillis >= timeToShoot)
						{
							//previousMillis = currentMillis;
							shoot();
							timeIsRunning = false;
						}
					}
					else if(displayStat == false)
					{
						displayOn();
						
						
						
					}
						p_lcd->              setCursor        (0,0);
						p_lcd->      print        ("Bilder: ");
						p_lcd->      print        (images);
					break;
				}
			}
			break;
		}
		case SerienAufnahmeMode:
		{
			switch(unterModeSerienAufnahme)
			{
				
				case SerieSetAmount:
				{
					
					p_lcd->      setCursor        (0,0);
					p_lcd->      print        ("Anzahl Bilder: ");
					p_lcd->      setCursor        (0,1);
					p_lcd->      print        (SeriePictures);
					p_lcd->      print        ("   ");
					break;
				}
				case SerieSetInterval:
				{
					
					p_lcd->      setCursor        (0,0);
					p_lcd->      print        ("Interval: ");
					p_lcd->      setCursor        (0,1);
					p_lcd->      print        (SerieInterval);
					p_lcd->      print        ("   ");
					break;
				}
				case SerieRun:
				{
					p_lcd->      setCursor        (0,0);
					p_lcd->      print        ("Bilder:  ");
					p_lcd->      print        (images);
					p_lcd->      print        ("   ");
					
					if((currentMillis - previousMillis >= SerieInterval) && deactivate == false)
						{
							previousMillis = currentMillis;
							shoot();
							if(SerienAufnahmeIsRunning != true)
							{
								SerienAufnahmeIsRunning = true;
							}
							if(images == SeriePictures)
							{
								SerienAufnahmeIsRunning = false;
								deactivate = true;
							}
						}
					break;
				}
			}
			break;
		}
		default:
		{
		Serial.print("Error: unknown mode: ");
		Serial.println(mode);
		break;
		}
	}
}
void Intervalometer::setLight()
{
	analogWrite(brightnessPin,light);
}
//╔════════════════BUTTONS═════════════════╗
//║										   ║
void Intervalometer::handleUpButton()
{
	switch(mode)
	{
		case IntervalMode:
		{
			switch(unterModeInterval)
			{
				case IntervalSetzen:
				{
						lastIntervall++;
						if(lastIntervall>600)
							lastIntervall = 600;
					break;
					}		
				case AufnahmezeitSetzen:
				{
						lastTime += 60;
						if(lastTime>86400)
							lastTime = 86400;
				break;
				}
			}
			break;
		}	
		case Hauptmenue:
		{
			//referenceTime = currentMillis;
			passedTime = currentMillis - referenceTime;
			if(currentMillis - previousMillis > 500)
			{
				p_lcd -> clear();
				previousMillis = currentMillis;
				//lastMenueMode = MenueMode;
				MenueMode++;
				if(MenueMode > funktionen)
				{
					MenueMode = funktionen;
				}
				//p_lcd->clear();
			}
			
			
			
		break;
		}
		case BlitzMode:
		{
			switch(unterModeBlitz)
			{
					case ToleranzSetzen:
			{
				toleranz +=5;
				if(toleranz > 1000)
					toleranz = 1000;
			break;
			}
			
			case TaktSetzen:
			{
				takt++;
				if(takt>1000)
					takt = 1000;
			break;
			}
			}
		break;
		}		
		case ZeitAusloeserMode:
		{
			
			//passedTime = currentMillis - referenceTime;
			
			
			switch(unterModeZeitAusloeser)
			{
				case ZeitAusloeserSetup:
				{
					timeToShoot = timeToShoot+1000;
					if(timeToShoot > 18000000)
					{
						timeToShoot = 18000000;			//ist 5 Stunden
					}
				break;
				}
			}
				
			
			//Serial.println(timeToShoot);
			break;
		}
		case PushToShootMode:
		{
			if(displayStat == false)
			{
				displayOn();
			}
			break;
		}
		case SerienAufnahmeMode:
		{
			switch(unterModeSerienAufnahme)
			{
				case SerieSetAmount:
				{
					SeriePictures = SeriePictures + 1;
					if(SeriePictures > 600)						//600 Bilder in 60 sec
					{SeriePictures = 600;}
					break;
				}
				case SerieSetInterval:
				{
					SerieInterval = SerieInterval + 100;		
					if(SerieInterval > 60000)					//60 sec
					{SerieInterval = 60000;}
					break;
				}
				case SerieRun:
				{
					if(displayStat == false)
					{
						displayOn();
					}
					break;
				}
			}
			
			break;
		}
		default:
		{
		Serial.print("Error");
		break;
		}
	}
}
void Intervalometer::handleDownButton()
{
	switch(mode)
	{
		case IntervalMode:
		{
			switch(unterModeInterval)
			{
				case IntervalSetzen:
				{
					lastIntervall--;
					if(lastIntervall<5)
						lastIntervall = 5;
				break;
				}	
				case AufnahmezeitSetzen:
				{
					lastTime -= 60;
					if(lastTime<60)
						lastTime = 60;
				break;
				}
			}
			break;
		}
		case Hauptmenue:
		{
			if(currentMillis - previousMillis > 500)
			{
				p_lcd -> clear();
				previousMillis = currentMillis;
				lastMenueMode = MenueMode;
				MenueMode--;
				if(MenueMode < 1)
				{
					MenueMode = 1;
				}
			}
			
			//p_lcd->clear();
			
		break;
		}
		case BlitzMode:
		{
			switch(unterModeBlitz)
			{
				case ToleranzSetzen:
				{
					toleranz -=5;
					if(toleranz < 1)
						toleranz = 1;
				break;
				}			
				case TaktSetzen:
				{
					takt--;
					if(takt<0)
						takt = 0;
				break;
				}
			}
			break;
		}
		case ZeitAusloeserMode:
		{
			
			//passedTime = currentMillis - referenceTime;
			
			switch(unterModeZeitAusloeser)
			{
				case ZeitAusloeserSetup:
				{
					timeToShoot = timeToShoot-1000;
					if(timeToShoot<1000)
					{
						timeToShoot = 1000;
					}	
				break;
				}
			}
			
			//Serial.println(timeToShoot);
			break;
		}
		case PushToShootMode:
		{
			
			if(displayStat == true)
			{
				displayOff();
			}
			break;
		}
		case SerienAufnahmeMode:
		{
			switch(unterModeSerienAufnahme)
			{
				case SerieSetAmount:
				{
					SeriePictures = SeriePictures -1;
					if(SeriePictures <1)
					{SeriePictures = 1;}
					break;
				}
				case SerieSetInterval:
				{
					SerieInterval = SerieInterval - 100;
					if(SerieInterval <300)
					{SerieInterval = 300;}
					break;
				}
				case SerieRun:
				{
					if(displayStat == true)
					{
						displayOff();
					}
					break;
				}
			}
			break;
		}
		default:
		{
		Serial.print("Error");
		break;
		}
	}
}
void Intervalometer::handleLightUpButton()
{
	if(mode != HelligkeitSetzenMode)
	{
		p_lcd->clear();
		lastMode = mode;
		mode = HelligkeitSetzenMode;
	}
	else
	{
	light -= 3;
	if(light<0)
	{
		light = 0;
	}
	setLight();
	}	
	
}
void Intervalometer::handleLightDownButton()
{
	if(mode != HelligkeitSetzenMode)
	{
		p_lcd->clear();
		lastMode = mode;
		mode = HelligkeitSetzenMode;
	}
	else
	{
	light += 3;
	if(light>253)
		light = 253;
	
	setLight();
	}
}
void Intervalometer::handleOkButton()
{
	p_lcd->clear();
	switch(mode)
	{
		case IntervalMode:
		{
			switch(unterModeInterval)
			{
				case IntervalSetzen:
				{
					lastMode 				= mode;
					lastUnterModeInterval 	= unterModeInterval;
					unterModeInterval 		= AufnahmezeitSetzen;
				break;
				}
				case AufnahmezeitSetzen:
				{
					lastUnterModeInterval 	= unterModeInterval;
					unterModeInterval 		= KontrolleInterval;
				break;
				}
				case KontrolleInterval:
				{
					lastUnterModeInterval 	= unterModeInterval;
					unterModeInterval 		= IntervalRun;
					mode					= countdown;
					shootTime 				= lastTime;			
				break;
				}	
				case IntervalRun:
				{
					digitalWrite(focusPin,LOW);		//focus
					//lastMode = mode;
					lastUnterModeInterval 	= unterModeInterval;
					unterModeInterval 		= AbschlussInfoInterval;
					stopRunning();
				break;
				}
				case AbschlussInfoInterval:
				{
					//lastMode = mode;
					mode = Hauptmenue;
					unterModeInterval = IntervalSetzen;
					reset();
				break;
				}
			}
			break;
		}
		case HelligkeitSetzenMode:
		{
			switch(lastMode)
			{
				case IntervalMode:
				{
					mode	=	IntervalMode;
				}			
				case Hauptmenue:
				{
					//lastMode = mode;
					mode = Hauptmenue;
					break;
				}
				case BlitzMode:
				{
					mode 	=	BlitzMode;
				}
				case ZeitAusloeserMode:
				{
					//lastMode = mode;
					mode = ZeitAusloeserMode;
					break;
				}
				case PushToShootMode:
				{
					//lastMode = mode;
					mode = PushToShootMode;
					break;
				}
				case SerienAufnahmeMode:
				{
					//lastMode = mode;
					mode = SerienAufnahmeMode;
					break;
				}
			}
				
		break;
		}	
		case BlitzMode:
		{
			switch(unterModeBlitz)
			{
				case ToleranzSetzen:
				{
					lastMode 			= 	mode;
					lastUnterModeBlitz 	=	unterModeBlitz;
					unterModeBlitz		=	TaktSetzen;
					
				break;
				}			
				case TaktSetzen:
				{
					//lastMode 			= 	mode;
					lastUnterModeBlitz 	=	unterModeBlitz;
					unterModeBlitz		=	KontrolleBlitz;
				break;
				}
				case KontrolleBlitz:
				{
					//lastMode 			= 	mode;
					lastUnterModeBlitz 	=	unterModeBlitz;
					unterModeBlitz		=	BlitzRun;	
					mode				= 	countdown;
				break;
				}
				case BlitzRun:
				{
					//Serial.println("stop Blitz");
					digitalWrite(focusPin,LOW);		//focus
					//lastMode = mode;
					lastUnterModeBlitz 	=	unterModeBlitz;
					unterModeBlitz		=	AbschlussinfoBlitz;	
					stopRunning();
				break;
				}
				case AbschlussinfoBlitz:
				{
					unterModeBlitz 	= ToleranzSetzen;
					lastMode	   	= mode;
					mode 			= Hauptmenue;
					reset();
				break;
				}
			}
			break;
		}
		case Hauptmenue:
		{
			lastMode	= mode;
			switch(MenueMode)
			{
				
				case HauptmenueAuswahl_1:	
				{
					
					mode = IntervalMode;
					break;
				}
				case HauptmenueAuswahl_2:	
				{
					mode = BlitzMode;
					break;
				}
				case HauptmenueAuswahl_3:	
				{
					digitalWrite(focusPin,HIGH);		//focus
					mode = PushToShootMode;
					break;
				}
				case HauptmenueAuswahl_4:
				{
					
					mode = ZeitAusloeserMode;
					break;
				}
				case HauptmenueAuswahl_5:
				{
					mode = SerienAufnahmeMode;
					break;
				}
			}
			break;
		}
		case ZeitAusloeserMode:
		{
			switch(unterModeZeitAusloeser)
			{
				case ZeitAusloeserSetup:
				{
					lastUnterModeZeitAusloeser 	= 	ZeitAusloeserSetup;
					unterModeZeitAusloeser	  	= 	ZeitAusloeserRun;
					break;
				}
				case ZeitAusloeserRun:
				{
					digitalWrite(focusPin,HIGH);		//focus
					if(timeIsRunning == false)
					{
						previousMillis = currentMillis;
					}
					timeIsRunning = true;
					//Serial.println(timeIsRunning);
					break;
				}
			}
			break;
		}
		case PushToShootMode:
		{
			shoot();
			break;
		}
		case countdown:
		{
			if(fastStart == false)
			{
				fastStart = true;
			}
			break;
		}
		case SerienAufnahmeMode:
		{
			switch(unterModeSerienAufnahme)
			{
				case SerieSetAmount:
				{
					lastMode = mode;
					lastUnterModeSerienAufnahme = 	SerieSetAmount;
					unterModeSerienAufnahme 	= 	SerieSetInterval;
					break;
				}
				case SerieSetInterval:
				{
					lastUnterModeSerienAufnahme 	= SerieSetInterval;
					unterModeSerienAufnahme			= SerieRun;
					//
					mode = countdown;
					break;
				}
				case SerieRun:
				{
					
					if(deactivate == false && SerienAufnahmeIsRunning == true)
					{
						
						deactivate = true;
					}
					else if(deactivate == true && SerienAufnahmeIsRunning == true)
					{
						
						deactivate = false;
					}
					
					if(SerienAufnahmeIsRunning == false)
					{
						digitalWrite(focusPin,LOW);		//focus
						images = 0;
						deactivate = false;
						lastMode = mode;
						mode = countdown;
					}
					break;
				}
			}
			break;
		}
		default:
		{
		Serial.print("Error-->Mode: ");
		Serial.print(mode);
		break;
		}
	}
}
void Intervalometer::handleBackButton()
{
	p_lcd->clear();
	
	lastMode = mode;
	switch(mode)
	{
		case IntervalMode:
		{
			switch(unterModeInterval)
			{
				case IntervalSetzen:
				{
					reset();
					//mode = Hauptmenue;
					//MenueMode = lastMenueMode;
					
				break;
				}
				case AufnahmezeitSetzen:
				{
					unterModeInterval = IntervalSetzen;
				break;
				}
				case KontrolleInterval:
				{
					unterModeInterval = AufnahmezeitSetzen;
				break;
				}
			}
			break;
		}
		case BlitzMode:
		{
			switch(unterModeBlitz)
			{
				case ToleranzSetzen:
				{
					//mode = Hauptmenue;
					//toleranz 		= 100;
					//takt 			= 5;
					reset();
					//MenueMode = lastMenueMode;
				break;
				}                                                                                       
				case TaktSetzen:
				{
					unterModeBlitz = ToleranzSetzen;
				break;
				}
				case KontrolleBlitz:
				{
					unterModeBlitz = TaktSetzen;
				break;
				}
			}
			break;
		}
		case PushToShootMode:
		{
			digitalWrite(focusPin,LOW);		//focus
			//images	= 0;
			//mode 	= 	Hauptmenue;
			if(displayStat == false)
			{
				displayOn();
			}
			reset();
			//MenueMode = lastMenueMode;
			break;
		}
		case ZeitAusloeserMode:
		{
			switch(unterModeZeitAusloeser)
			{
				case ZeitAusloeserSetup:
				{
					//images 	= 0;
					//mode 	= Hauptmenue;
					reset();
					//MenueMode = lastMenueMode;
					break;
				}
				case ZeitAusloeserRun:
				{
					digitalWrite(focusPin,LOW);		//focus
					unterModeZeitAusloeser = ZeitAusloeserSetup;
					break;
				}
			}
			break;
		}
		case SerienAufnahmeMode:
		{
			switch(unterModeSerienAufnahme)
			{
				case SerieSetAmount:
				{
					//mode = Hauptmenue;
					//SeriePictures = 5;
					
					reset();
					//MenueMode = lastMenueMode;
					break;
				}
				case SerieSetInterval:
				{
					unterModeSerienAufnahme = SerieSetAmount;
					break;
				}
				case SerieRun:
				{
					digitalWrite(focusPin,LOW);		//focus
					displayOn();
					images 		= 0;
					unterModeSerienAufnahme = SerieSetInterval;
					SerienAufnahmeIsRunning = false;
					deactivate 				= false;
					//reset();
					break;
				}
			}
			break;
		}
	}
}
//║										   ║
//╚════════════════BUTTONS═════════════════╝
void Intervalometer::intro()
{

}
void Intervalometer::checkButtons()
{
   
   if((mode == IntervalMode)||
      (mode == HelligkeitSetzenMode)||
	  (mode == Hauptmenue)||
	  (mode == BlitzMode)||
	  (mode == ZeitAusloeserMode)||
	  (mode == PushToShootMode)||
	  (mode == SerienAufnahmeMode))
   {
		p_buttonLightDown->        checkButton();
		p_buttonLightUp->          checkButton();  
   }
   if((mode == IntervalMode)||
	  (mode == Hauptmenue)||
	  (mode == BlitzMode)||
	  (mode == ZeitAusloeserMode)||
	  (mode == PushToShootMode)||
	  (mode == SerienAufnahmeMode))
   {
      p_buttonUp->                    checkButton();
	  p_buttonDown->                  checkButton();
   }
   if((mode == IntervalMode)||
	  (mode == BlitzMode)||
	  (mode == ZeitAusloeserMode)||
	  (mode == PushToShootMode)||
	  (mode == SerienAufnahmeMode))
   {
	p_buttonBack				->checkButton();
   }  
   
   //if(mode != countdown)
   {
	p_buttonOk->                    checkButton();
   }
}
void Intervalometer::stopRunning()
{
  displayOn();

  p_lcd->    setCursor   (0, 0);
  p_lcd->    print       ("Gestopt     ");
  delay(1000);
  p_lcd->    clear();
}
void Intervalometer::reset()
{
	//light 			= 0;
	setFocus		= true;
	mode 			= Hauptmenue;
	//MenueMode		= HauptmenueAuswahl_1;
	unterModeZeitAusloeser=ZeitAusloeserSetup;
	lastUnterModeZeitAusloeser=ZeitAusloeserSetup;
	SerienAufnahmeIsRunning = false;
	timeIsRunning	= false;
	displayStat		= true;
	timeToShoot 	= 1000;		//in ms
	shootTime       = 0;
	passedTime		= 0;
	minuten 		= 0;
	stunden 		= 0;
	images			= 0;
	lastTime		= 60;
	lastMode		= 0;
	lastIntervall	= 5;
	referenceTime   = 0;
	
	countDown		= 10;
	fastStart		= false;
	
	currentMillis   = 0;
	previousMillis  = 0;
	previousMillis2	= 0;
	
	toleranz 		= 100;
	takt 			= 5;
	
	ldrValue		= 0;
	lastLdrValue	= 0;
	
	
	unterModeSerienAufnahme = SerieSetAmount;
	lastUnterModeSerienAufnahme = SerieSetAmount;
	SerieInterval		= 500;		//ms
	SeriePictures		= 5;
	deactivate			= false;
	if(displayStat == false)
	{
		displayOn();
	}
	
}
void Intervalometer::shoot()
{
	 
      p_led->           toggle();
      digitalWrite      (shuterPin, HIGH);
      delay             (1);
      p_led->           toggle();
      digitalWrite      (shuterPin, LOW);
      images++;
}
void Intervalometer::displayOff()
{
	displayStat = false;
	digitalWrite(brightnessPin,HIGH);
	digitalWrite(displayPin, LOW);
}
void Intervalometer::displayOn()
{
	displayStat = true;
	digitalWrite(displayPin, HIGH);
	p_lcd->init();
	setLight();
	p_lcd -> 	clear();
	p_lcd ->    createChar(2, kamera);
	p_lcd -> 	createChar(1,PfeilDown);
	p_lcd -> 	createChar(0,PfeilUp);
}