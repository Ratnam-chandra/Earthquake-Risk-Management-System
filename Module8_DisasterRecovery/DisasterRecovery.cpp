#include "DisasterRecovery.h"
#include <iomanip>

void DisasterRecovery::createRecoveryPlan()
{
    cout << "\n===== DISASTER RECOVERY PLANNING =====\n";

    cout << "Enter City Name: ";
    cin >> plan.cityName;

    cout << "Enter Population: ";
    cin >> plan.population;

    cout << "Enter Risk Score: ";
    cin >> plan.riskScore;

    // Recovery Cost Calculation
    plan.recoveryCost =
        plan.population *
        plan.riskScore *
        100;

    // Shelter Calculation
    plan.sheltersNeeded =
        plan.population / 1000;

    if (plan.population % 1000 != 0)
        plan.sheltersNeeded++;

    // Rescue Teams
    plan.rescueTeamsNeeded =
        (plan.population / 5000) + 1;

    // Medical Teams
    plan.medicalTeamsNeeded =
        (plan.population / 3000) + 1;

    cout << "\nRecovery Plan Generated Successfully!\n";
}

void DisasterRecovery::displayRecoveryPlan()
{
    cout << "\n====================================";
    cout << "\n DISASTER RECOVERY REPORT";
    cout << "\n====================================";

    cout << "\nCity Name           : "
         << plan.cityName;

    cout << "\nPopulation          : "
         << plan.population;

    cout << "\nRisk Score          : "
         << plan.riskScore;

    cout << "\nEstimated Cost (Rs) : "
         << fixed << setprecision(0)
         << plan.recoveryCost;

    cout << "\nShelters Needed     : "
         << plan.sheltersNeeded;

    cout << "\nRescue Teams Needed : "
         << plan.rescueTeamsNeeded;

    cout << "\nMedical Teams Needed: "
         << plan.medicalTeamsNeeded;

    cout << "\n====================================\n";
}