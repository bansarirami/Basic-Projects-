#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAR_LANES 2
#define TRUCK_LANE 1
#define BUS_LANE 1

// Function for only positive value input
int getValidInput(char *message)
{
    char buffer[100];
    char *endptr;
    long value;

    while(1)
    {
        printf("%s", message);

        if(fgets(buffer, sizeof(buffer), stdin) == NULL)
            continue;

        buffer[strcspn(buffer, "\n")] = 0;

        if(strlen(buffer) == 0)
        {
            printf("Invalid input! Enter a valid positive integer.\n");
            continue;
        }

        value = strtol(buffer, &endptr, 10);

        if(*endptr != '\0')
        {
            printf("Invalid input! Enter only positive integer.\n");
            continue;
        }

        if(value <= 0)
        {
            printf("Invalid input! Value must be greater than 0.\n");
            continue;
        }

        return (int)value;
    }
}

int main()
{
    int totalMinutes;
    int i, j;

    int carQueue[CAR_LANES] = {0};
    int truckQueue[TRUCK_LANE] = {0};
    int busQueue[BUS_LANE] = {0};

    int vehicleID = 1;

    printf("===== Toll Booth Management System =====\n\n");

    totalMinutes = getValidInput("Enter total simulation minutes: ");

    for(i = 1; i <= totalMinutes; i++)
    {
        int cars, trucks, buses;

        printf("\n----- Minute %d -----\n", i);

        cars   = getValidInput("Enter number of Cars arriving: ");
        trucks = getValidInput("Enter number of Trucks arriving: ");
        buses  = getValidInput("Enter number of Buses arriving: ");

        //  CARS 
        for(j = 0; j < cars; j++)
        {
            int minLane = 0;

            for(int k = 1; k < CAR_LANES; k++)
            {
                if(carQueue[k] < carQueue[minLane])
                    minLane = k;
            }

            int waitingTime = carQueue[minLane];
            int tollAmount = 80;
            int discount = waitingTime * 1;
            int finalAmount = tollAmount - discount;

            if(finalAmount < 0)
                finalAmount = 0;

            printf("\nVehicle ID: %d", vehicleID++);
            printf("\nType: Car");
            printf("\nLane Assigned: %d", minLane + 1);
            printf("\nWaiting Time: %d minute(s)", waitingTime);
            printf("\nFinal Toll: Rs.%d\n", finalAmount);

            carQueue[minLane]++;
        }

        //  TRUCKS 
        for(j = 0; j < trucks; j++)
        {
            int waitingTime = truckQueue[0];
            int tollAmount = 200;
            int discount = waitingTime * 1;
            int finalAmount = tollAmount - discount;

            if(finalAmount < 0)
                finalAmount = 0;

            printf("\nVehicle ID: %d", vehicleID++);
            printf("\nType: Truck");
            printf("\nLane Assigned: 1");
            printf("\nWaiting Time: %d minute(s)", waitingTime);
            printf("\nFinal Toll: Rs.%d\n", finalAmount);

            truckQueue[0]++;
        }

        //  BUSES 
        for(j = 0; j < buses; j++)
        {
            int waitingTime = busQueue[0];
            int tollAmount = 150;
            int discount = waitingTime * 1;
            int finalAmount = tollAmount - discount;

            if(finalAmount < 0)
                finalAmount = 0;

            printf("\nVehicle ID: %d", vehicleID++);
            printf("\nType: Bus");
            printf("\nLane Assigned: 1");
            printf("\nWaiting Time: %d minute(s)", waitingTime);
            printf("\nFinal Toll: Rs.%d\n", finalAmount);

            busQueue[0]++;
        }

        // PROCESSING SIMULATION 

        for(j = 0; j < CAR_LANES; j++)
            if(carQueue[j] > 0)
                carQueue[j]--;

        if(truckQueue[0] > 0)
            truckQueue[0]--;

        if(busQueue[0] > 0)
            busQueue[0]--;
    }

    printf("\n===== Simulation Completed Successfully =====\n");

    return 0;
}
