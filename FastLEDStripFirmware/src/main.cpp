#include "FastLEDStrip.h"
#include <Arduino.h> // Su un file .ino non è necessario
#include <FastLED.h>

/*
Schetch che utilizza la libreria FasLED
*/

// La dichiarazione delle funzioni non è necessaria nel file .ino

// Setup inizale di Arduino
void setup()
{
	// Configurazione iniziale della LED strip
    LEDStripSetup();
}

// Loop standard di Arduino
void loop()
{
    FastLED.show();

    FastLED.delay( 1000 / UPDATES_PER_SECOND );

    // Accendo tutta la strip alla massima luminosità di colore Turchese
    SetFullLenghtMode( ON );

    // Spengo tutta la strip
    SetFullLenghtMode( OFF );
}
