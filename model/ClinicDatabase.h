#ifndef CLINICDATABASE_H
#define CLINICDATABASE_H

#include "PatientRecord.h"
#include <vector>
#include <memory>
#include <string>

namespace SCAPMS {

    class ClinicDatabase {

        private:

        // Collection of patient records
        std::vector<std::shared_ptr<PatientRecord>> patients;

        public:

        // Constructor
        ClinicDatabase();

        // Add a patient
        bool addPatient(std::shared_ptr<PatientRecord> patient);

        // Remove a patient using patient ID
        bool removePatient(std::string patientID);

        // Find a patient using patient ID
        std::shared_ptr<PatientRecord> findPatient(std::string patientID) const;

        // Display all patients
        void displayAllPatients() const;

        // Get total number of patients
        int getPatientCount() const;

        // Get all patient records
        const std::vector<std::shared_ptr<PatientRecord>>& getPatients() const;

        // Array to store the 10 most recent patients
        std::shared_ptr<PatientRecord> recentPatients[10];

    };

}

#endif