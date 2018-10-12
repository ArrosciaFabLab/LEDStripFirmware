#include "FastLEDStrip.h"   // Libreria di gestione della striscia LED
#include <Arduino.h>        // Su un file .ino non è necessario
#include <FastLED.h>        // Libreria FastLED

/*
Schetch di test sulla striscia LED che utilizza la libreria FasLED
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

    /*for ( size_t i = 0; i < 29 ; i++ )
    {
        SetFollowMode( ON, 75 + i );
        SetFollowMode( OFF, 75 + i );
    }
    for ( size_t i = 29; i > 0 ; i-- )
    {
        SetFollowMode( ON, 75 + i );
        SetFollowMode( OFF, 75 + i );
    }*/

    //CylonBounce( 255, 0, 0, 4, 10, 50 ); // Red
    //CylonBounce( 64,224, 208, 4, 10, 50 ); // Turquoise
    //CylonBounce( 32, 178, 170, 4, 10, 50 ); // LightSeaGreen
    //CylonBounce( 72, 209, 204, 4, 10, 50 ); // MediumTurquoise
    CylonBounce( 0, 206, 209, 4, 10, 50 ); // DarkTurquoise
}
