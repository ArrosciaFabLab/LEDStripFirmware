#include "FastLEDStrip.h"
#include <FastLED.h>

// Array dei LED che rappresenta la strip
CRGB objLEDStrip[ NUM_LEDS ];

CRGBPalette16 currentPalette;

// Colore utilizzato per la striscia LED
//CRGB objColor = CRGB::LightSeaGreen;  // 0x20B2AA - rgb(32,178,170)
//CRGB objColor = CRGB::Turquoise;  // 0x40E0D0 - rgb(64,224,208)
//CRGB objColor = CRGB::MediumTurquoise;    // 0x48D1CC - rgb(72,209,204)
CRGB objColor = CRGB::DarkTurquoise; // 0x00CED1 - rgb(0,206,209)

/*
 *    Funzione che imposta i parametri di inizializzazione dell strip
 */
void LEDStripSetup()
{
	// Ritardo prima dell'accensione di 3 secondi
    delay( 3000 );

    // Inizializza la strip di LED
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>( objLEDStrip, NUM_LEDS ).setCorrection( TypicalLEDStrip );

    // Imposta la luminosità iniziale dei LED
    FastLED.setBrightness( BRIGHTNESS );
}

/*
 *    Funzione che imposta la strip tutta accesa o spenta alla massima luminosità
 *    con tutti i LED di colore Blu Turchese (se accesa).
 *    Il parametro booleano indica se accendere o spegnere la strip.
 *    L'animazione di accensione avviene dal centro verso l'esterno.
 *    L'animazione di spegnimento avviene dall'esterno verso il centro.
 *    Il tipo di fade è come quello usato nell'occhio dei Cycloni, di Super Car e detto Larson scanner
 */
void SetFullLenghtMode( bool bState )
{

    // Si vuole spegnere totalmente la strip
    if ( bState == OFF )
    {
        for ( size_t i = 0; i < ( ( NUM_LEDS / 2 ) - 1 ); i++ )
        {
            // Parto dal primo LED a sinistra e spengo tutti i LED da
            // sinistra a destra fino al metà del numero dei LED della strip
            objLEDStrip[i] = CRGB::Black;
			FastLED.show();

            // Parto dal primo LED a destra e spengo tutti i LED da
            // destra a sinistra fino al metà del numero dei LED della strip
            objLEDStrip[NUM_LEDS - 1 - i] = CRGB::Black;
			FastLED.show();

			delay( WAIT_TO_NEXT );
        }
    }

	// Si vuole accendere totalmente la strip con una animazione che parte dal primo LED
    // al centro e proseguendo da entrambi i lati verso l'esterno
    else
    {
        for ( size_t i = 1; i < ( ( NUM_LEDS / 2 ) + 1 ); i++ )
        {
            // Parto dal primo LED al centro e accendo tutti i LED da
            // destra a sinistra fino al primo LED a sinistra della strip
            objLEDStrip[( NUM_LEDS / 2 ) - i] = objColor;
			FastLED.show();

            // Parto dal primo LED a destra di quello al centro e accendo
            // tutti i LED a destra fino all'ultimo LED a destra della strip
            objLEDStrip[i + ( ( NUM_LEDS / 2 ) - 1)] = objColor;
			FastLED.show();

			delay( WAIT_TO_NEXT );
        }
    }
}

/*
 *    Funzione che imposta la strip tutta spenda (150 LED) ad eccezzione di 1 LED in corrispondenza
 *    della coordinata X della punta della fresa che sarà acceso alla massima luminosità di colore
 *    Turchese. I LED a destra e sinistra del precedente LED dimuniranno progressivamente la loro
 *    luminosità del colore Turchese fino allo spegnimento. La larghezza in LED del cursore è definita.
 *    L'animazione di accensione avviene dal centro verso l'esterno.
 *    L'animazione di spegnimento avviene dall'esterno verso il centro.
 *    Il tipo di fade è come quello usato nell'occhio dei Cycloni, di Super Car e detto Larson scanner
 */
void SetFollowMode( bool bState, int nBitXPosition )
{
    int nBrightness = 0;

    // Si vuole spegnere il cursore della strip
    if ( bState == OFF )
    {

        for ( size_t i = ( ( CURSOR_LEDS / 2 ) + 1 ); i < 1; i-- )
        {
            // Spengo il LED a destra predente LED spento
            objLEDStrip[( nBitXPosition + i )] = CRGB::Black;
            FastLED.show();

            // Spengo il LED a sinistra predente LED spento
    		objLEDStrip[( nBitXPosition - i )] = CRGB::Black;
            FastLED.show();
        }

        // Spengo il LED centrale al cursore
        objLEDStrip[( nBitXPosition )] = CRGB::Black;
        FastLED.show();
    }
    else // Si vuole accendere il cursore della strip
    {

        // Accendo il LED centrale al cursore con il colore Turchese alla massima luminosità
        objLEDStrip[( nBitXPosition )] = objColor;
        FastLED.show();

        for ( size_t i = 1; i < ( ( CURSOR_LEDS / 2 ) + 1 ); i++ )
        {
            // Spengo il LED a destra predente LED spento
            objLEDStrip[( nBitXPosition + i )] = objColor;
            objLEDStrip[( nBitXPosition + i )].fadeLightBy( nBrightness );
            FastLED.show();

            // Spengo il LED a sinistra predente LED spento
    		objLEDStrip[( nBitXPosition - i )] = objColor;
            objLEDStrip[( nBitXPosition - i )].fadeLightBy( nBrightness );
            FastLED.show();

            nBrightness = nBrightness + FADE_RATE;
        }
        /*objLEDStrip[( nBitXPosition )] = CRGB::MidnightBlue;
        FastLED.show();

        objLEDStrip[( nBitXPosition + 1 )] = CRGB::Blue;
        FastLED.show();
		objLEDStrip[( nBitXPosition - 1 )] = CRGB::Blue;
        FastLED.show();
		objLEDStrip[( nBitXPosition + 2 )] = CRGB::Turquoise;
        FastLED.show();
		objLEDStrip[( nBitXPosition - 2 )] = CRGB::Turquoise;
        FastLED.show();
		objLEDStrip[( nBitXPosition + 3 )] = CRGB::MediumTurquoise;
        FastLED.show();
		objLEDStrip[( nBitXPosition - 3 )] = CRGB::MediumTurquoise;
        FastLED.show();
		objLEDStrip[( nBitXPosition + 4 )] = CRGB::PaleTurquoise;
        FastLED.show();
		objLEDStrip[( nBitXPosition - 4 )] = CRGB::PaleTurquoise;
        FastLED.show();
		objLEDStrip[( nBitXPosition + 5 )] = CRGB::LightSkyBlue;
        FastLED.show();
		objLEDStrip[( nBitXPosition - 5 )] = CRGB::LightSkyBlue;
        FastLED.show();
		objLEDStrip[( nBitXPosition + 6 )] = CRGB::LightCyan;
        FastLED.show();
		objLEDStrip[( nBitXPosition - 6 )] = CRGB::LightCyan;
        FastLED.show();*/
    }
}

void CylonBounce( int red, int green, int blue, int EyeSize, int SpeedDelay, int ReturnDelay)
{
    for( int i = 0; i < NUM_LEDS - EyeSize - 2; i++ )
    {
        fill_solid( objLEDStrip, NUM_LEDS, CRGB::Black );
        objLEDStrip[ i ] = CRGB( red / 10, green / 10, blue / 10 );
        FastLED.show();

        for( int j = 1; j <= EyeSize; j++ )
        {
            objLEDStrip[i + j] = CRGB( red, green, blue );
            FastLED.show();
        }
        objLEDStrip[i + EyeSize + 1] = CRGB( red / 10, green / 10, blue / 10 );
        FastLED.show();
        delay( SpeedDelay );
    }
    delay( ReturnDelay );
    for( int i = NUM_LEDS - EyeSize - 2; i > 0; i-- )
    {
        fill_solid( objLEDStrip, NUM_LEDS, CRGB::Black );
        objLEDStrip[ i ] = CRGB( red / 10, green / 10, blue / 10 );
        FastLED.show();
        for( int j = 1; j <= EyeSize; j++ )
        {
            objLEDStrip[i + j] = CRGB( red, green, blue );
            FastLED.show();
        }
        objLEDStrip[i + EyeSize + 1] = CRGB( red / 10, green / 10, blue / 10 );
        FastLED.show();
        delay( SpeedDelay );
  }
  delay( ReturnDelay );
}
