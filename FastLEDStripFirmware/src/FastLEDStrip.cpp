#include <FastLEDStrip.h>

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
            objLEDStrip[( NUM_LEDS / 2 ) - i] = CRGB::Turquoise;
			FastLED.show();

            // Parto dal primo LED a destra di quello al centro e accendo
            // tutti i LED a destra fino all'ultimo LED a destra della strip
            objLEDStrip[i + ( ( NUM_LEDS / 2 ) - 1)] = CRGB::Turquoise;
			FastLED.show();
			
			delay( WAIT_TO_NEXT );
        }
    }
}

/*
 *    Funzione che imposta la strip tutta spenda (150 LED) ad eccezzione di 3 LED in corrispondenza
 *    della coordinata X della punta della fresa che saranno accesi alla massima luminosità di colore
 *    Turchese. I 5 LED a destra e sinistra di questi 3 LED dimuniranno progressivamente la loro
 *    luminosità del colore Turchese fino allo spegnimento al 6° LED a destra e a sinistra.
 *    L'animazione di accensione avviene dal centro verso l'esterno.
 *    L'animazione di spegnimento avviene dall'esterno verso il centro.
 */
void SetFollowMode( bool bState, int nBitXPosition )
{
    // Si vuole spegnere il cursore della strip
    if ( bState == OFF )
    {
		// a
    }
    else // Si vuole accendere il cursore della strip
    {
		// b
    }
}
