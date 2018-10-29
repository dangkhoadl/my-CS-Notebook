

int main(int agrc, char *argv[]) {
    if (agrc == 3) {
        //Input
        const char *inputFileName(argv[1]);
        FILE *fileIn;
        fileIn = fopen(inputFileName, "r");

        if (!fileIn) {
            printf("File does not exist !!!\n");
            return 0;
        }

        //Read

        fclose(fileIn);

        //Process


        //Output
        const std::string outputFileName(argv[2]);
        std::ofstream fileOut;
        fileOut.open(outputFileName);

        //Write

        fileOut.close();
    }
    else {
        const char* inputProgram(argv[0]);
        printf("Plz rerun the %s program\n", inputProgram);
    }

    return 0;
}
