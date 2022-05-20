#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>





void isConversionValid(int numArgs, char userChoice);
void starter();




void distance() {
    double distInput;
    char userSuffix;
    char newUnitType;
    int rv;
    char newLineChecker;
    printf("Enter the distance followed by its suffix (I,F,Y,M): ");
    rv = scanf(" %lf %c", &distInput, &userSuffix); 
    scanf("%c", &newLineChecker);
    if(newLineChecker != '\n') {
      printf(" Invalid formatting. Ending program.\n");
      exit(0);
      }
    if (rv == 0) {
      printf(" Invalid formatting. Ending program.\n");
      exit(0);
    }
    userSuffix = toupper(userSuffix);
    if (userSuffix != 'I' && userSuffix != 'F' && userSuffix != 'Y' && userSuffix != 'M') {
      printf("%c is not a valid distance type. Ending program.\n", userSuffix);
      exit(0);
    }

    printf(" Enter the new unit type (I,F,Y,M): ");
    scanf(" %c", &newUnitType);
    scanf("%c", &newLineChecker);
    if(newLineChecker != '\n') {
      printf(" Invalid formatting. Ending program.\n");
      exit(0);
      }
    newUnitType = toupper(newUnitType);
    if (newUnitType != 'I' && newUnitType != 'F' && newUnitType != 'Y' && newUnitType != 'M') {
      printf("%c is not a valid distance type. Ending program.\n", newUnitType);
      exit(0);
    }
    double newDist;
    if (userSuffix == 'I') {
      if (newUnitType == 'I') {
        newDist = distInput;
      } else if (newUnitType == 'F') {
        newDist = distInput / 12.0;
      } else if (newUnitType == 'Y') {
        newDist= distInput / 36.0;
      } else if (newUnitType == 'M') {
        newDist = distInput / 63360.0;
      }
    } else if (userSuffix == 'F') {
       if (newUnitType == 'F') {
        newDist = distInput;
      } else if (newUnitType == 'Y') {
        newDist = distInput / 3.0;
      } else if (newUnitType == 'M') {
        newDist= distInput / 5280.0;
      } else if (newUnitType == 'I') {
        newDist = distInput * 12.0;
      }
    } else if (userSuffix == 'Y') {
       if (newUnitType == 'Y') {
        newDist = distInput;
      } else if (newUnitType == 'M') {
        newDist = distInput / 1760.0;
      } else if (newUnitType == 'I') {
        newDist= distInput * 36.0; 
      } else if (newUnitType == 'F') {
        newDist = distInput * 3.0;
      }
    } else if (userSuffix == 'M') {
       if (newUnitType == 'M') {
        newDist = distInput;
      } else if (newUnitType == 'I') {
        newDist = distInput * 63360.0;
      } else if (newUnitType == 'F') {
        newDist= distInput * 5280.0;
      } else if (newUnitType == 'Y') {
        newDist = distInput * 1760.0;
      }
    } else {
      printf("%c is not a valid distance type. Ending program.\n", userSuffix);
      exit(0);
    }
 
    printf("%.2lf%c is %.2lf%c\n", distInput, userSuffix, newDist, newUnitType);
}



void isConversionValid(int numArgs, char userChoice) {
    if (!isalpha(userChoice) || numArgs != 1) {
        printf(" Invalid formatting. Ending program.\n");
        exit(0);
    }
    if (userChoice != 'T' && userChoice != 'D') {
        printf("Unknown conversion type %c chosen. Ending program.\n", userChoice);
        exit(0);
    }
  
}
void temperature() {
    double tempInput;
    char userSuffix;
    char newUnitType;
    int rv;
    char newLineChecker;
    printf("Enter the temperature followed by its suffix (F, C, or K):");
    rv = scanf(" %lf %c", &tempInput, &userSuffix);
    scanf("%c", &newLineChecker);
    if(newLineChecker != '\n') {
      printf(" Invalid formatting. Ending program.\n");
      exit(0);
      }
    if (rv==0) {
      printf(" Invalid formatting. Ending program.\n");
      exit(0);
    }
    userSuffix = toupper(userSuffix);
    if (userSuffix != 'F' && userSuffix != 'C' && userSuffix != 'K') {
      printf(" %c is not a valid temperature type. Ending program.\n", userSuffix);
      exit(0);
    }
    printf(" Enter the new unit type (F, C, or K): ");
    scanf(" %c", &newUnitType);
    scanf("%c", &newLineChecker);
    if(newLineChecker != '\n') {
      printf(" Invalid formatting. Ending program.\n");
      exit(0);
      }
    
    newUnitType = toupper(newUnitType);
    if(newUnitType != 'F' && newUnitType != 'C' && newUnitType != 'K') {
      printf(" %c is not a valid temperature type. Ending program.\n", newUnitType);
      exit(0);
    }
    double newTemp;
    if (userSuffix == 'F') {
      if (newUnitType == 'F') {
        newTemp = tempInput;
      } else if (newUnitType == 'C') {
        newTemp = (tempInput - 32.0) * 5.0 / 9.0;
      } else if (newUnitType == 'K') {
        newTemp=(tempInput - 32.0) * (5.0 / 9.0) + 273.15;
      }
    } else if (userSuffix == 'C') {
      if (newUnitType =='C') {
        newTemp = tempInput;
      } else if (newUnitType == 'F') {
        newTemp = (tempInput * 9.0 / 5.0) + 32.0;
        
      } else if (newUnitType == 'K') {
        newTemp = tempInput + 273.15;

      }
    } else if (userSuffix == 'K') {
      if (newUnitType =='K') {
        newTemp = tempInput;
      } else if (newUnitType == 'C') {
        newTemp = tempInput - 273.15;
        
      } else if (newUnitType == 'F') {
        newTemp = (tempInput - 273.15) * (9.0 / 5.0) + 32.0;

      }
    }
 
    printf("%.2lf%c is %.2lf%c\n", tempInput, userSuffix, newTemp, newUnitType);
}


void starter() {
    char userChoice; 
    char newLineChecker;
    printf("Pick the type of conversion that you would like to do.\n");
  	printf("T or t for temperature\n");
  	printf("D or d for distance\n");
  	printf("Enter your choice: ");
    int numArgs = scanf("%c", &userChoice);
    scanf("%c", &newLineChecker);
    if(newLineChecker != '\n') {
      printf(" Invalid formatting. Ending program.\n");
      exit(0);
      }
 

    userChoice = toupper(userChoice); 
    isConversionValid(numArgs, userChoice);
    if (userChoice == 'T') {
        temperature();
    } else if (userChoice == 'D') {
        distance();
    }
}

int main() {
    starter();
    return 0;
}