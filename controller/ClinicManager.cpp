#include "ClinicManager.h"

using namespace std;

namespace SCAPMS {

    // Constructor
    ClinicManager::ClinicManager() {
    }

    // Register a patient
    bool ClinicManager::registerPatient(shared_ptr<PatientRecord> patient) {
        return database.addPatient(patient);
    }

    // Remove a patient
    bool ClinicManager::removePatient(string patientID) {
        return database.removePatient(patientID);
    }

    // Find a patient
    shared_ptr<PatientRecord> ClinicManager::findPatient(string patientID) const {
        return database.findPatient(patientID);
    }

    // Display all patients
    void ClinicManager::displayPatients() const {
        database.displayAllPatients();
    }

    // Get total number of patients
    int ClinicManager::getTotalPatients() const {
        return database.getPatientCount();
    }

    // Access the database
    ClinicDatabase& ClinicManager::getDatabase() {
        return database;
    }

}