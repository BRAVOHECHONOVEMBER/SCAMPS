#ifndef EMERGENCYPATIENT_H
#define EMERGENCYPATIENT_H

#include "PatientRecord.h"
#include "Appointable.h"
#include "Appointment.h"

#include <vector>
#include <string>

namespace SCAPMS {

    class EmergencyPatient : public PatientRecord, public Appointable {

        private:

        int urgencyLevel;

        std::vector<Appointment> appointments;

        public:

        // Constructor
        EmergencyPatient(std::string id,
                     std::string patientName,
                     int patientAge,
                     std::string patientContact,
                     int urgency);

        // Implements PatientRecord's pure virtual functions
        std::string getPatientType() const override;
        void displaySummary() const override;

        // Implements Appointable's pure virtual functions
        bool scheduleAppointment(
            const Appointment& appointment) override;

        bool cancelAppointment(
            std::string appointmentID) override;

        // Urgency level getter
        int getUrgencyLevel() const;

        // Returns the patient's appointments
        const std::vector<Appointment>& getAppointments() const;

    };

}

#endif