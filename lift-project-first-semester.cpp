#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    const int totalLifts = 6;
    const int totalFloors = 30;

    int liftPosition[totalLifts];

    cout << "Enter the current floor of each lift:\n";

    for (int i = 0; i < totalLifts; i++)
    {
        do
        {
            cout << "Lift " << i + 1 << ": ";
            cin >> liftPosition[i];
        }
        while (liftPosition[i] < 1 || liftPosition[i] > totalFloors);
    }

    while (true)
    {
        int requestFloor;

        cout << "\nEnter requested floor (1-30) or 0 to exit: ";
        cin >> requestFloor;

        if (requestFloor == 0)
            break;

        if (requestFloor < 1 || requestFloor > totalFloors)
        {
            cout << "Invalid floor.\n";
            continue;
        }

        int nearestLift = 0;
        int minDistance = abs(requestFloor - liftPosition[0]);

        for (int i = 1; i < totalLifts; i++)
        {
            int distance = abs(requestFloor - liftPosition[i]);

            if (distance < minDistance)
            {
                minDistance = distance;
                nearestLift = i;
            }
        }

        cout << "Nearest Lift: " << nearestLift + 1 << endl;
        cout << "Lift moved from Floor " << liftPosition[nearestLift]
             << " to Floor " << requestFloor << endl;

        liftPosition[nearestLift] = requestFloor;
    }

    return 0;
}