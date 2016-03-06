
/*Intervalometer
Author 			: Alex Krieg
Version			: 1.3.6		
compatibility 	: Hardware 1.0.0
Date			: 3.3.2016

copyright by BlenderEr Informatics®
All rights reserved
*/


#include "Intervalometer.h"

 Intervalometer::Intervalometer(int bOK,int bUp,int bDown,int blUp,int blDown,int bback,boolean logicLevel,int shuter,int display,int light,int LDR)
{
	p_lcd 					= new LiquidCrystal_I2C(0x20,16,2);
	p_buttonLightUp  		= new Button(blUp,		logicLevel);
	p_buttonLightDown		= new Button(blDown,	logicLevel);
	p_buttonUp            	= new Button(bUp,		logicLevel);
	p_buttonDown          	= new Button(bDown, 	logicLevel);
	p_buttonOk            	= new Button(bOK,		logicLevel);
	p_buttonBack			= new Button(bback,		logicLevel);
	p_led	 				= new Led(13);
	
	
	
	ldrPin					= LDR;
	shuterPin				= shuter;
	displayPin				= display;
	brightnessPin			= light;
	
	light 			= 0;
	mode 			= Hauptmenue;
	MenueMode		= HauptmenueAuswahl_1;
	ZeitAusloeserMode=ZeitAusloeserSetup;
	lastZeitAusloeserMode=ZeitAusloeserSetup;
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
	lastIntervall	= 1;
	referenceTime   = 0;
	
	countDown		= 10;
	fastStart		= false;
	
	currentMillis   = 0;
	previousMillis  = 0;
	
	toleranz 		= 100;
	takt 			= 5;
	
	ldrValue		= 0;
	lastLdrValue	= 0;
	
	
	SerienAufnahmeMode = SerieSetAmount;
	lastSerienAufnahmeMode = SerieSetAmount;
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
	
	Serial.println("SETUP DONE");	
}

void Intervalometer::run()
{
	checkButtons();
	currentMillis = millis();
	switch(mode)
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
	case HelligkeitSetzen:
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
	case AufnahmezeitSetzen:
	{
		// Anzeige Display aktualisieren
		
		stunden                  = lastTime / 3600;
		minuten                  = lastTime / 60;
		
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
		if(currentMillis - previousMillis > lastIntervall*100)
		{
			previousMillis =  currentMillis;
			shoot();
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
	
	
	//------------------------------------------------------------------------------------------------------------------\\
	
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
		
		/*p_lcd->                  setCursor    (0, 0);
		p_lcd->	print("Zeitraffer: Rauf         ");
		p_lcd->                  setCursor    (0, 1);
		p_lcd-> print("Blitz: Runter         ");*/
	break;
	}
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
	case countdown:
	{
			if(fastStart == true)
			{
				countDown = 0;
				fastStart = false;
			}
			referenceTime = currentMillis;
			if((countDown==0 && lastMode == KontrolleInterval)/* || fastStart == true*/)
			{  
			    displayOff();
			    lastMode = mode;
			    mode = IntervalRun;
				/*if(fastStart == true)
				{fastStart = false;}*/
			}
			
			if((countDown==0 && lastMode == KontrolleBlitz) /*|| fastStart == true*/)
			{  
				displayOff();
				lastMode = mode;
				mode = BlitzRun;
				ldrValue = analogRead(ldrPin);
				lastLdrValue = ldrValue;
				/*if(fastStart == true)
				{fastStart = false;}*/
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
	case PushToShoot:
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
	case ZeitAusloeser:
	{
		
		switch(ZeitAusloeserMode)
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
					/*Serial.print(currentMillis);
					Serial.print(" ");
					Serial.print(previousMillis);
					Serial.print("    ");
					Serial.println(timeToShoot);*/
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
	case SerienAufnahme:
	{
		switch(SerienAufnahmeMode)
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
						if(images == SeriePictures)
						{
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
		
		case Hauptmenue:
		{
			//referenceTime = currentMillis;
			passedTime = currentMillis - referenceTime;
			if(currentMillis - previousMillis > 500)
			{
				p_lcd -> clear();
				previousMillis = currentMillis;
				MenueMode++;
				if(MenueMode > funktionen)
				{
					MenueMode = funktionen;
				}
				//p_lcd->clear();
			}
			
			
			/*
			p_lcd->clear();
			lastMode = mode;
			mode = IntervalSetzen;*/
		break;
		}
		
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
		case ZeitAusloeser:
		{
			
			//passedTime = currentMillis - referenceTime;
			/*
			Serial.print(passedTime);
			Serial.print(" ");
			Serial.print(currentMillis);
			Serial.print(" ");
			Serial.print(previousMillis);
			Serial.print("    ");
			Serial.println(timeToShoot);
			
			if(currentMillis - previousMillis >= 3000)
			{
				previousMillis = currentMillis;
				timeToShoot = timeToShoot+900;
				
			}*/
			
			switch(ZeitAusloeserMode)
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
		case PushToShoot:
		{
			if(displayStat == false)
			{
				displayOn();
			}
			break;
		}
		case SerienAufnahme:
		{
			switch(SerienAufnahmeMode)
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
		case IntervalSetzen:
		{
			lastIntervall--;
			if(lastIntervall<1)
				lastIntervall = 1;
		break;
		}
		
		case AufnahmezeitSetzen:
		{
			lastTime -= 60;
			if(lastTime<60)
				lastTime = 60;
		break;
		}
		
		case Hauptmenue:
		{
			if(currentMillis - previousMillis > 500)
			{
				p_lcd -> clear();
				previousMillis = currentMillis;
				MenueMode--;
				if(MenueMode < 1)
				{
					MenueMode = 1;
				}
			}
			
			//p_lcd->clear();
			/*
			p_lcd->clear();
			lastMode = mode;
			mode = ToleranzSetzen;*/
		break;
		}
		
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
		case ZeitAusloeser:
		{
			
			//passedTime = currentMillis - referenceTime;
			/*
			Serial.print(passedTime);
			Serial.print(" ");
			Serial.print(currentMillis);
			Serial.print(" ");
			Serial.print(previousMillis);
			Serial.print("    ");
			Serial.println(timeToShoot);
			
			if(currentMillis - previousMillis >= 3000)
			{
				previousMillis = currentMillis;
				timeToShoot = timeToShoot+900;
				
			}*/
			
			
				timeToShoot = timeToShoot-1000;
				if(timeToShoot<1000)
				{
					timeToShoot = 1000;
				}
			
			
			//Serial.println(timeToShoot);
			break;
		}
		case PushToShoot:
		{
			
			if(displayStat == true)
			{
				displayOff();
			}
			break;
		}
		case SerienAufnahme:
		{
			switch(SerienAufnahmeMode)
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
					if(SerieInterval <100)
					{SerieInterval = 100;}
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
	if(mode != HelligkeitSetzen)
	{
		p_lcd->clear();
		lastMode = mode;
		mode = HelligkeitSetzen;
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
	if(mode != HelligkeitSetzen)
	{
		p_lcd->clear();
		lastMode = mode;
		mode = HelligkeitSetzen;
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
		case IntervalSetzen:
		{
			lastMode = mode;
			mode = AufnahmezeitSetzen;
		break;
		}
		
		case HelligkeitSetzen:
		{
			switch(lastMode)
			{
				case IntervalSetzen:
				{
					lastMode = mode;
					mode = IntervalSetzen;
					break;
				}
				case AufnahmezeitSetzen:
				{
					lastMode = mode;
					mode = AufnahmezeitSetzen;
					break;
				}
				case AbschlussInfoInterval:
				{
					lastMode = mode;
					mode = AbschlussInfoInterval;
					break;
				}
				case Hauptmenue:
				{
					lastMode = mode;
					mode = Hauptmenue;
					break;
				}
				case ToleranzSetzen:
				{
					lastMode = mode;
					mode = ToleranzSetzen;
					break;
				}
				case TaktSetzen:
				{
					lastMode = mode;
					mode = TaktSetzen;
					break;
				}
				case AbschlussinfoBlitz:
				{
					lastMode = mode;
					mode = AbschlussinfoBlitz;
					break;
				}
				case ZeitAusloeser:
				{
					lastMode = mode;
					mode = ZeitAusloeser;
					break;
				}
				case PushToShoot:
				{
					lastMode = mode;
					mode = PushToShoot;
					break;
				}
				case SerienAufnahme:
				{
					lastMode = mode;
					mode = SerienAufnahme;
					break;
				}
			}
				
		break;
		}
		
		case AufnahmezeitSetzen:
		{
			lastMode = mode;
			mode = KontrolleInterval;
		break;
		}
		
		case KontrolleInterval:
		{
			lastMode = mode;
			mode = countdown;
			shootTime = lastTime;			
		break;
		}
		
		case IntervalRun:
		{
			lastMode = mode;
			mode = AbschlussInfoInterval;
			stopRunning();
		break;
		}
		
		case ToleranzSetzen:
		{
			lastMode = mode;
			mode = TaktSetzen;
		break;
		}
		
		case TaktSetzen:
		{
			lastMode = mode;
			mode = KontrolleBlitz;
		break;
		}
		
		case KontrolleBlitz:
		{
			lastMode = mode;
			mode = countdown;		
		break;
		}
		
		case BlitzRun:
		{
			Serial.println("stop Blitz");
			lastMode = mode;
			mode = AbschlussinfoBlitz;
			stopRunning();
		break;
		}
		case AbschlussInfoInterval:
		{
			lastMode = mode;
			mode = Hauptmenue;
			reset();
		break;
		}
		case AbschlussinfoBlitz:
		{
			lastMode = mode;
			mode = Hauptmenue;
			reset();
		break;
		}
		case Hauptmenue:
		{
			lastMode	= mode;
			switch(MenueMode)
			{
				
				case HauptmenueAuswahl_1:	
				{
					
					mode = IntervalSetzen;
					break;
				}
				case HauptmenueAuswahl_2:	
				{
					mode = ToleranzSetzen;
					break;
				}
				case HauptmenueAuswahl_3:	
				{
					mode = PushToShoot;
					break;
				}
				case HauptmenueAuswahl_4:
				{
					mode = ZeitAusloeser;
					break;
				}
				case HauptmenueAuswahl_5:
				{
					mode = SerienAufnahme;
					break;
				}
			}
			break;
		}
		case ZeitAusloeser:
		{
			switch(ZeitAusloeserMode)
			{
				case ZeitAusloeserSetup:
				{
					lastZeitAusloeserMode = ZeitAusloeserMode;
					ZeitAusloeserMode	 = ZeitAusloeserRun;
					break;
				}
				case ZeitAusloeserRun:
				{
					
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
		case PushToShoot:
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
		case SerienAufnahme:
		{
			switch(SerienAufnahmeMode)
			{
				case SerieSetAmount:
				{
					lastSerienAufnahmeMode = SerieSetAmount;
					SerienAufnahmeMode = SerieSetInterval;
					break;
				}
				case SerieSetInterval:
				{
					lastSerienAufnahmeMode = SerieSetAmount;
					SerienAufnahmeMode = SerieRun;
					break;
				}
				case SerieRun:
				{
					deactivate = true;
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
		case KontrolleInterval:
		{
			mode = AufnahmezeitSetzen;
		break;
		}
		
		case AufnahmezeitSetzen:
		{
			mode = IntervalSetzen;
		break;
		}
		case IntervalSetzen:
		{
			mode = Hauptmenue;
			//reset();
		break;
		}
		case ToleranzSetzen:
		{
			mode = Hauptmenue;
			toleranz 		= 100;
			takt 			= 5;
			//reset();
		break;
		}                                                                                       
		case TaktSetzen:
		{
			mode = ToleranzSetzen;
		break;
		}
		case KontrolleBlitz:
		{
			mode = TaktSetzen;
		break;
		}
		case PushToShoot:
		{
			images	= 0;
			mode 	= Hauptmenue;
			if(displayStat == false)
			{
				displayOn();
			}
			break;
		}
		case ZeitAusloeser:
		{
			switch(ZeitAusloeserMode)
			{
				case ZeitAusloeserSetup:
				{
					images 	= 0;
					mode 	= Hauptmenue;
					break;
				}
				case ZeitAusloeserRun:
				{
					ZeitAusloeserMode = ZeitAusloeserSetup;
					break;
				}
			}
			break;
		}
		case SerienAufnahme:
		{
			switch(SerienAufnahmeMode)
			{
				case SerieSetAmount:
				{
					mode = Hauptmenue;
					SeriePictures = 5;
					break;
				}
				case SerieSetInterval:
				{
					SerienAufnahmeMode = SerieSetAmount;
					break;
				}
				case SerieRun:
				{
					SerienAufnahmeMode = SerieSetInterval;
					deactivate = false;
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
   
   if((mode == IntervalSetzen)||
      (mode == HelligkeitSetzen)||
	  (mode == AufnahmezeitSetzen)||
	  (mode == AbschlussInfoInterval)||
	  (mode == AbschlussinfoBlitz)||
	  (mode == Hauptmenue)||
	  (mode == ToleranzSetzen)||
	  (mode == TaktSetzen)||
	  (mode == ZeitAusloeser)||
	  (mode == PushToShoot)||
	  (mode == SerienAufnahme))
   {
		p_buttonLightDown->        checkButton();
		p_buttonLightUp->          checkButton();  
   }
   if((mode == IntervalSetzen)||
	  (mode == Hauptmenue)||
	  (mode == ToleranzSetzen)||
	  (mode == TaktSetzen)||
      (mode == AufnahmezeitSetzen)||
	  (mode == ZeitAusloeser)||
	  (mode == PushToShoot)||
	  (mode == SerienAufnahme))
   {
      p_buttonUp->                    checkButton();
	  p_buttonDown->                  checkButton();
   }
   if((mode == KontrolleInterval)||
	  (mode == IntervalSetzen)||
	  (mode == TaktSetzen)||
	  (mode == ToleranzSetzen)||
	  (mode == KontrolleBlitz)||
      (mode == AufnahmezeitSetzen)||
	  (mode == ZeitAusloeser)||
	  (mode == PushToShoot)||
	  (mode == SerienAufnahme))
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
	light 			= 0;
	mode 			= Hauptmenue;
	MenueMode		= HauptmenueAuswahl_1;
	ZeitAusloeserMode=ZeitAusloeserSetup;
	lastZeitAusloeserMode=ZeitAusloeserSetup;
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
	lastIntervall	= 1;
	referenceTime   = 0;
	
	countDown		= 10;
	fastStart		= false;
	
	currentMillis   = 0;
	previousMillis  = 0;
	
	toleranz 		= 100;
	takt 			= 5;
	
	ldrValue		= 0;
	lastLdrValue	= 0;
}
void Intervalometer::shoot()
{
	 
      p_led->           toggle();
      digitalWrite      (shuterPin, HIGH);
      delay             (2);
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
}