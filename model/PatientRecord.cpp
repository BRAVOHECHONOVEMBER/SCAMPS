#include "PatientRecord.h"
#include "ClinicException.h"

using namespace std;

namespace SCAPMS {

    // Constructor
    PatientRecord::PatientRecord(string id, string patientName,
                             int patientAge, string patientContact)
        : patientID(id),
        name(patientName),
        age(patientAge),
        contact(patientContact) {

        if (patientID.empty() || name.empty() || contact.empty()) {
            throw ClinicException("Patient information cannot be empty.");
        }

        if (age <= 0) {
            throw ClinicException("Patient's age must be greater than zero.");
        }
    }

    // Destructor
    PatientRecord::~PatientRecord() {
}

    // Getters

    string PatientRecord::getPatientID() const {
        return patientID;
    }

    string PatientRecord::getName() const {
        return name;
    }

    int PatientRecord::getAge() const {
        return age;
    }

    string PatientRecord::getContact() const {
        return contact;
    }

    // Setters

    void PatientRecord::setName(string newName) {

        if (newName.empty()) {
            throw ClinicException("Patient name cannot be empty.");
        }

        name = newName;
    }

    void PatientRecord::setAge(int newAge) {

        if (newAge <= 0) {
            throw ClinicException("Patient age must be greater than zero.");
        }

        age = newAge;
    }

    void PatientRecord::setContact(string newContact) {

        if (newContact.empty()) {
            throw ClinicException("Patient contact cannot be empty.");
        }

    contact = newContact;
}

}