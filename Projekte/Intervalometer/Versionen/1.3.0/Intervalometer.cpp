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
	mode 			= 6;
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
	
	currentMillis   = 0;
	previousMillis  = 0;
	
	toleranz 		= 100;
	takt 			= 5;
	
	ldrValue		= 0;
	lastLdrValue	= 0;
	
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
	p_lcd->     createChar(1, kamera);
 
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
	case IntervallSetzen:
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
	
	case Kontrolle1:
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
	
	case Running1:
	{
	passedTime = currentMillis - referenceTime;
    if (passedTime > shootTime*1000)
    {
      mode = Abschlussinfo1;
	  stopRunning();
    }
	if(currentMillis - previousMillis > lastIntervall*100)
    {
		previousMillis =  currentMillis;
		shoot();
    }
	break;
	}
	case Abschlussinfo1:
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
		p_lcd->                  setCursor    (0, 0);
		p_lcd->	print("Zeitraffer: Rauf         ");
		p_lcd->                  setCursor    (0, 1);
		p_lcd-> print("Blitz: Runter         ");
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
	
	case Kontrolle2:
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
	
	case Running2:
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
	
	case Abschlussinfo2:
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
	
	referenceTime = currentMillis;
			if(countDown==0 && lastMode == Kontrolle1)
			{  
			  digitalWrite(brightnessPin,HIGH);
			  digitalWrite(displayPin, LOW);
			  lastMode = mode;
			  mode = Running1;
			}
			
			if(countDown==0 && lastMode == Kontrolle2)
			{  
			  digitalWrite(brightnessPin,HIGH);
			  digitalWrite(displayPin, LOW);
			  lastMode = mode;
			  mode = Running2;
			  ldrValue = analogRead(ldrPin);
			  lastLdrValue = ldrValue;
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


void Intervalometer::handleUpButton()
{
	switch(mode)
	{
		case IntervallSetzen:
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
			p_lcd->clear();
			lastMode = mode;
			mode = IntervallSetzen;
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
		case IntervallSetzen:
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
			p_lcd->clear();
			lastMode = mode;
			mode = ToleranzSetzen;
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
		case IntervallSetzen:
		{
			lastMode = mode;
			mode = AufnahmezeitSetzen;
		break;
		}
		
		case HelligkeitSetzen:
		{
				if(lastMode == IntervallSetzen)
				{
					lastMode = mode;
					mode = IntervallSetzen;
				}
				
				if(lastMode == AufnahmezeitSetzen)
				{
					lastMode = mode;
					mode = AufnahmezeitSetzen;
				}
				
				if(lastMode == Abschlussinfo1)
				{
					lastMode = mode;
					mode = Abschlussinfo1;
				}
				if(lastMode == Hauptmenue)
				{
					lastMode = mode;
					mode = Hauptmenue;
				}
				if(lastMode == ToleranzSetzen)
				{
					lastMode = mode;
					mode = ToleranzSetzen;
				}
				if(lastMode == TaktSetzen)
				{
					lastMode = mode;
					mode = TaktSetzen;
				}
				if(lastMode == Abschlussinfo2)
				{
					lastMode = mode;
					mode = Abschlussinfo2;
				}
				
		break;
		}
		
		case AufnahmezeitSetzen:
		{
			lastMode = mode;
			mode = Kontrolle1;
		break;
		}
		
		case Kontrolle1:
		{
			lastMode = mode;
			mode = countdown;
			shootTime = lastTime;			
		break;
		}
		
		case Running1:
		{
			lastMode = mode;
			mode = Abschlussinfo1;
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
			mode = Kontrolle2;
		break;
		}
		
		case Kontrolle2:
		{
			lastMode = mode;
			mode = countdown;		
		break;
		}
		
		case Running2:
		{
			lastMode = mode;
			mode = Abschlussinfo2;
			stopRunning();
		break;
		}
		case Abschlussinfo1:
		{
			lastMode = mode;
			mode = Hauptmenue;
			reset();
		break;
		}
		case Abschlussinfo2:
		{
			lastMode = mode;
			mode = Hauptmenue;
			reset();
		break;
		}
		default:
		{
		Serial.print("Error");
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
		case Kontrolle1:
		{
			mode = AufnahmezeitSetzen;
		break;
		}
		
		case AufnahmezeitSetzen:
		{
			mode = IntervallSetzen;
		break;
		}
		case IntervallSetzen:
		{
			mode = Hauptmenue;
			reset();
		break;
		}
		case ToleranzSetzen:
		{
			mode = Hauptmenue;
			reset();
		break;
		}
		case TaktSetzen:
		{
			mode = ToleranzSetzen;
		break;
		}
		case Kontrolle2:
		{
			mode = TaktSetzen;
		break;
		}
	}
}
void Intervalometer::intro()
{

}

void Intervalometer::checkButtons()
{
   
   if((mode == IntervallSetzen)||
      (mode == HelligkeitSetzen)||
	  (mode == AufnahmezeitSetzen)||
	  (mode == Abschlussinfo1)||
	  (mode == Abschlussinfo2)||
	  (mode == Hauptmenue)||
	  (mode == ToleranzSetzen)||
	  (mode == TaktSetzen))
   {
		p_buttonLightDown->        checkButton();
		p_buttonLightUp->          checkButton();  
   }
   if((mode == IntervallSetzen)||
	  (mode == Hauptmenue)||
	  (mode == ToleranzSetzen)||
	  (mode == TaktSetzen)||
      (mode == AufnahmezeitSetzen))
   {
      p_buttonUp->                    checkButton();
	  p_buttonDown->                  checkButton();
   }
   if((mode == Kontrolle1)||
	  (mode == IntervallSetzen)||
	  (mode == TaktSetzen)||
	  (mode == ToleranzSetzen)||
	  (mode == Kontrolle2)||
      (mode == AufnahmezeitSetzen))
   {
	p_buttonBack				->checkButton();
   }  
   
   if((mode != countdown)&&(mode != Hauptmenue))
   {
	p_buttonOk->                    checkButton();
   }
}

void Intervalometer::stopRunning()
{
  digitalWrite(displayPin, HIGH);
  p_lcd->init();
  setLight();
  
  p_lcd->    setCursor   (0, 0);
  p_lcd->    print       ("Gestopt     ");
  delay(1000);
  p_lcd->    clear();
}

void Intervalometer::reset()
{
	mode 			= 6;
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