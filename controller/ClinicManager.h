#ifndef CLINICMANAGER_H
#define CLINICMANAGER_H

#include "../Model/ClinicDatabase.h"
#include "../Model/PatientRecord.h"
#include "../Model/Appointment.h"

#include <memory>
#include <string>
#include <queue>
#include <stack>

namespace SCAPMS {

// Types of administrative operations
enum class AdminOperationType {
    PatientDeleted,
    PatientModified,
    AppointmentRemoved
};

// Stores information needed to undo an operation
struct AdminOperation {

    AdminOperationType type;

    std::shared_ptr<PatientRecord> patient;

    std::string previousName;
    int previousAge = 0;
    std::string previousContact;

    std::shared_ptr<Appointment> appointment;
};

class ClinicManager {

private:

    // Patient database
    ClinicDatabase database;

    // Queue for waiting patients
    std::queue<std::shared_ptr<PatientRecord>> waitingPatients;

    // Stack for undo operations
    std::stack<AdminOperation> undoStack;

public:

    // Constructor
    ClinicManager();

    // Patient management
    bool registerPatient(std::shared_ptr<PatientRecord> patient);

    bool removePatient(std::string patientID);

    std::shared_ptr<PatientRecord> findPatient(std::string patientID) const;

    void displayPatients() const;

    int getTotalPatients() const;

    // Access the database
    ClinicDatabase& getDatabase();

    // Waiting queue operations
    void addToWaitingQueue(std::shared_ptr<PatientRecord> patient);

    std::shared_ptr<PatientRecord> getNextWaitingPatient();

    bool isWaitingQueueEmpty() const;

    // Record administrative operations
    void recordPatientDeletion(std::shared_ptr<PatientRecord> patient);

    void recordPatientModification(
        std::shared_ptr<PatientRecord> patient,
        std::string oldName,
        int oldAge,
        std::string oldContact
    );

    void recordAppointmentRemoval(
        std::shared_ptr<PatientRecord> patient,
        const Appointment& appointment
    );

    // Undo the most recent administrative operation
    bool undoLastOperation();

};

}

#endif