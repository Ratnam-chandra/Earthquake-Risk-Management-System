#include "Module1_DataManagement/Earthquake.h"
#include "Module8_DisasterRecovery/DisasterRecovery.h"

int main()
{
    EarthquakeManager manager;
    DisasterRecovery recovery;

    int choice;

    do
    {
        cout << "\n===== EARTHQUAKE RISK MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Record\n";
        cout << "2. Display Records\n";
        cout << "3. Save Data\n";
        cout << "4. Load Data\n";
        cout << "5. Display Risk Report\n";
        cout << "6. Statistics Report\n";
        cout << "7. Prediction Report\n";
        cout << "8. Create Road Network\n";
        cout << "9. Find Safe Route\n";
        cout << "10. Mark Dangerous City\n";
        cout << "11. Find Safest Route\n";
        cout << "12. City Risk Classification\n";
        cout << "13. Add Evacuation Center\n";
        cout << "14. Display Evacuation Centers\n";
        cout << "15. Recommend Evacuation Center\n";
        cout << "16. Disaster Recovery Planning\n";
        cout << "17. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
{
    case 1:
        manager.addRecord();
        break;

    case 2:
        manager.displayRecords();
        break;

    case 3:
        manager.saveToFile();
        break;

    case 4:
        manager.loadFromFile();
        break;

    case 5:
        manager.displayRiskReport();
        break;

    case 6:
        manager.displayStatistics();
        break;

    case 7:
        manager.displayPredictionReport();
        break;

    case 8:
        manager.createRoadNetwork();
        break;

    case 9:
        manager.findSafeRoute();
        break;

    case 10:
        manager.markDangerousCity();
        break;

    case 11:
        manager.findSafestRoute();
        break;

    case 12:
        manager.classifyCities();
        break;

    case 13:
        manager.addEvacuationCenter();
        break;

    case 14:
        manager.displayEvacuationCenters();
        break;

    case 15:
        manager.recommendEvacuationCenter();
        break;

     case 16:
        recovery.createRecoveryPlan();
        recovery.displayRecoveryPlan();
        break;

     case 17:
        cout << "\nProgram Closed.\n";
        break;

    default:
        cout << "\nInvalid Choice.\n";
}

} while(choice != 17);

    return 0;
}