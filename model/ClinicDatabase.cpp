#include "ClinicDatabase.h"
#include "../Utils/ClinicException.h"
#include <iostream>

using namespace std;

namespace SCAPMS {

    // Constructor
    ClinicDatabase::ClinicDatabase() {
    }

    // Add a patient
    bool ClinicDatabase::addPatient(shared_ptr<PatientRecord> patient) {

        if (patient == nullptr) {
            throw ClinicException("Invalid patient record.");
        }

        // Check if the patient ID already exists
        for (const auto& existingPatient : patients) {

            if (existingPatient->getPatientID() == patient->getPatientID()) {
                throw ClinicException("Patient ID already exists.");
            }
        }

        patients.push_back(patient);
        return true;
    }

    // Remove a patient using patient ID
    bool ClinicDatabase::removePatient(string patientID) {

        for (auto it = patients.begin(); it != patients.end(); ++it) {

            if ((*it)->getPatientID() == patientID) {
                patients.erase(it);
                return true;
            }
        }

        return false;
    }

    // Find a patient using patient ID
    shared_ptr<PatientRecord> ClinicDatabase::findPatient(string patientID) const {

        for (const auto& patient : patients) {

            if (patient->getPatientID() == patientID) {
                return patient;
            }
        }

        return nullptr;
    }

    // Display all patients
    void ClinicDatabase::displayAllPatients() const {

        if (patients.empty()) {
            cout << "No patients registered.\n";
            return;
        }

        for (const auto& patient : patients) {
            patient->displaySummary();
        }
    }

    // Get total number of patients
    int ClinicDatabase::getPatientCount() const {
        return static_cast<int>(patients.size());
    }

    // Get all patient records
    const vector<shared_ptr<PatientRecord>>& ClinicDatabase::getPatients() const {
        return patients;
    }

}