#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Constants
#define Domesticcustomercharge 90.0
#define Commercialcustomercharge 120.0
#define Electricitydutyrate 0.06
#define Fixedchargerate 10.0
#define Lossgain 0.01

// Function declarations
float calculateDomesticBill(float units);
float calculateCommercialBill(float units);

int main() {
    float totalEnergy, units, electricityDuty, contractedLoad, fixedCharges;
    int choice;

    // Ask user for billing type
    printf("Choose Billing Type: \n1. Domestic\n2. Commercial\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    // Validate billing type
    if (choice != 1 && choice != 2) {
        printf("Invalid billing type selected.\n");
        return 1;
    }

    // Input for contracted load
    printf("Enter Contracted Load (in kW): ");
    scanf("%f", &contractedLoad);
    if (contractedLoad <= 0) {
        printf("Invalid input. Please enter positive values.\n");
        return 1;
    }

    // Input for energy consumption
    printf("Enter Units Consumed: ");
    scanf("%f", &units);
    if (units <= 0) {
        printf("Invalid input. Please enter positive values.\n");
        return 1;
    }

    printf("\n----- ELECTRICITY BILL -----\n");

    fixedCharges = contractedLoad * Fixedchargerate ;
    electricityDuty = units *Electricitydutyrate ;

    if (choice == 1) {
        printf("Billing Type: Domestic\n");
        totalEnergy = calculateDomesticBill(units);

        printf("Energy Charges    : Rs %.2f\n", totalEnergy);
        printf("Fixed Charges     : Rs %.2f\n", fixedCharges);
        printf("Electricity Duty  : Rs %.2f\n", electricityDuty);
        printf("Customer Charges  : Rs %.2f\n", Domesticcustomercharge);
        printf("Surcharge         : Rs %.2f\n", 0.00);
        printf("Loss/Gain         : Rs %.2f\n", Lossgain);
        printf("-----------------------------\n");
        printf("Total Bill Amount : Rs %.2f\n", totalEnergy + fixedCharges + electricityDuty + Domesticcustomercharge + Lossgain);

    } else {
        printf("Billing Type: Commercial\n");
        totalEnergy = calculateCommercialBill(units);

        printf("Energy Charges    : Rs %.2f\n", totalEnergy);
        printf("Fixed Charges     : Rs %.2f\n", fixedCharges);
        printf("Electricity Duty  : Rs %.2f\n", electricityDuty);
        printf("Customer Charges  : Rs %.2f\n",Commercialcustomercharge );
        printf("Surcharge         : Rs %.2f\n", 0.00);
        printf("Loss/Gain         : Rs %.2f\n", Lossgain);
        printf("-----------------------------\n");
        printf("Total Bill Amount : Rs %.2f\n", totalEnergy + fixedCharges + electricityDuty + Commercialcustomercharge + Lossgain);
    }

    return 0;
}

// Function to calculate domestic bill based on units
float calculateDomesticBill(float units) {
    float total = 0;

    if (units <= 50)
        total = units * 1.95;
    else if (units <= 100)
        total = 50 * 1.95 + (units - 50) * 3.1;
    else if (units <= 200)
        total = 50 * 1.95 + 50 * 3.1 + (units - 100) * 4.8;
    else if (units <= 300)
        total = 50 * 1.95 + 50 * 3.1 + 100 * 4.8 + (units - 200) * 7.7;
    else if (units <= 400)
        total = 50 * 1.95 + 50 * 3.1 + 100 * 4.8 + 100 * 7.7 + (units - 300) * 9;
    else if (units <= 800)
        total = 50 * 1.95 + 50 * 3.1 + 100 * 4.8 + 100 * 7.7 + 100 * 9 + (units - 400) * 9.5;
    else
        total = 50 * 1.95 + 50 * 3.1 + 100 * 4.8 + 100 * 7.7 + 100 * 9 + 400 * 9.5 + (units - 800) * 10;

    return total;
}

// Function to calculate commercial bill based on units
float calculateCommercialBill(float units) {
    float total = 0;

    if (units <= 50)
        total = units * 7.0;
    else if (units <= 100)
        total = 50 * 7.0 + (units - 50) * 8.5;
    else if (units <= 300)
        total = 50 * 7.0 + 50 * 8.5 + (units - 100) * 9.9;
    else if (units <= 500)
        total = 50 * 7.0 + 50 * 8.5 + 200 * 9.9 + (units - 300) * 10.4;
    else
        total = 50 * 7.0 + 50 * 8.5 + 200 * 9.9 + 200 * 10.4 + (units - 500) * 11.0;

    return total;


}
