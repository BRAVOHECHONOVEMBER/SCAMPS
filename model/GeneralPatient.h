#ifndef GENERALPATIENT_H
#define GENERALPATIENT_H

#include "PatientRecord.h"
#include "Appointable.h"
#include "Appointment.h"

#include <vector>

namespace SCAPMS {

    class GeneralPatient : public PatientRecord, public Appointable {

        private:

        std::vector<Appointment> appointments;

        public:

        // Constructor
        GeneralPatient(std::string id, std::string patientName,
                   int patientAge, std::string patientContact);

        // Implementing PatientRecord's pure virtual functions
        std::string getPatientType() const override;
        void displaySummary() const override;

        // Implementing Appointable's pure virtual functions
        bool scheduleAppointment(
            const Appointment& appointment) override;

        bool cancelAppointment(
        std::string appointmentID) override;

        // Retrieve appointments
        const std::vector<Appointment>& getAppointments() const;

    };

}

#endif  