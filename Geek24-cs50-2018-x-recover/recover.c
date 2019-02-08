#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

#define BUFFERS 512

int main (int argc, string argv[])
{
    // Check for proper usage
    if (argc != 2)
    {
        printf("Usage: recover filename\n");
        return 1;
    }

    // Open card file
    FILE* infile = fopen(argv[1], "r");
    FILE* outfile = NULL;

    if (infile == NULL)
    {
        printf("Cannot open file.\n");
        return 1;
    }

    // Create buffer for JPEG image read
    unsigned char buffer[BUFFERS];

    // Counter for creating output files
    int counter = 0;

    // Keep track of whether JPEG has been found
    int found = 0;

    // Loops until end of file
    while (fread(buffer, BUFFERS, 1, infile) == 1)
    {
        // Checks for JPEG header info
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] == 0xe0)
        {
            // Checks if JPEG is found
            if (found == 1)
            {
                fclose(outfile);
            }
            else
            {
                found = 1;
            }

        char jpegname[8];
        sprintf(jpegname, "%03d.jpg", counter);
        outfile = fopen(jpegname, "a");
        counter++;
        }

        if (found == 1)
        {
            // Start writing the 512 byte blocks to outfile
            fwrite(&buffer, BUFFERS, 1, outfile);
        }
    }

    // Exit and close out open files.
    fclose(infile);
    fclose(outfile);

    return 0;

}