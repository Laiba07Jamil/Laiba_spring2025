#include <stdio.h>
#include <windows.h>

#pragma comment(lib, "winmm.lib")

int main()
{
    FILE *logFile;
    int output;
    long last_pos = 0;
    int is_playing = 0; // State variable: 0 = sound should be OFF, 1 = sound should be ON

    // --- Initial File Opening Logic ---
    logFile = fopen("logic.txt", "r");
    if (!logFile)
    {
        printf("Waiting for logic.txt to be created...\n");
        while ((logFile = fopen("logic.txt", "r")) == NULL)
        {
            Sleep(500);
        }
        printf("logic.txt found. Starting monitoring.\n");
    }
    else
    {
        printf("Monitoring existing logic.txt...\n");
        // Optional: Move to end if you only care about changes after starting
        // fseek(logFile, 0L, SEEK_END);
        // last_pos = ftell(logFile);
    }
    // --- End of Initial File Opening ---

    // Main infinite loop
    while (1)
    {
        fseek(logFile, last_pos, SEEK_SET); // Go to where we last read

        // Inner loop: Read all available new data
        while (fscanf(logFile, "%d", &output) == 1)
        {
            last_pos = ftell(logFile); // Update position *after* successful read

            if (output == 1)
            {
                // Logic wants sound ON
                if (!is_playing)
                { // Check if we are *not* already playing/looping
                    printf("State Change -> ON (Start Looping)\n");
                    // Use SND_LOOP flag
                    PlaySound(TEXT("alert.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
                    is_playing = 1; // Update state: We are now looping
                }
                // If is_playing was already 1, do nothing (sound continues looping)
            }
            else
            { // output == 0
                // Logic wants sound OFF
                if (is_playing)
                { // Check if we *are* currently looping
                    printf("State Change -> OFF (Stop Sound)\n");
                    // Stop any currently playing sound (including loops)
                    PlaySound(NULL, NULL, 0);
                    is_playing = 0; // Update state: We are now stopped
                }
                // If is_playing was already 0, do nothing (sound remains off)
            }
        } // End of inner reading loop

        clearerr(logFile); // Clear EOF/error flags for next check
        Sleep(200);        // Wait before checking file again (adjust as needed)
    } // End of outer infinite loop

    // --- Cleanup ---
    fclose(logFile);
    PlaySound(NULL, NULL, 0); // Ensure sound is off on exit
    return 0;
    // --- End of Cleanup ---
}