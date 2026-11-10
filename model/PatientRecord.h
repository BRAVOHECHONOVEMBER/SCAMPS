#ifndef PATIENTRECORD_H
#define PATIENTRECORD_H

#include <string>

namespace SCAPMS {

class PatientRecord {

    protected:
        std::string patientID;
        std::string name;
        int age;
        std::string contact;

    public:

        PatientRecord(std::string id, std::string patientName, int patientAge, std::string patientContact);

        virtual ~PatientRecord();

        // Getters
        std::string getPatientID() const;
        std::string getName() const;
        int getAge() const;
        std::string getContact() const;

        // Setters
        void setName(std::string newName);
        void setAge(int newAge);
        void setContact(std::string newContact);

        // Pure virtual functions
        virtual std::string getPatientType() const = 0;
        virtual void displaySummary() const = 0;

    };

}

#endif