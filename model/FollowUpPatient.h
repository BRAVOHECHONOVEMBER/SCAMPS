#ifndef FOLLOWUPPATIENT_H
#define FOLLOWUPPATIENT_H

#include "PatientRecord.h"
#include "Appointable.h"
#include "Appointment.h"
#include <vector>

namespace SCAPMS {

    class FollowUpPatient : public PatientRecord, public Appointable {

        private:
        std::vector<Appointment> appointments;
        std::string previousVisitDate;

        public:

        FollowUpPatient(std::string id, std::string patientName,
                    int patientAge, std::string patientContact,
                    std::string lastVisitDate);

        std::string getPatientType() const override;

        void displaySummary() const override;

        bool scheduleAppointment(const Appointment& appointment) override;

        bool cancelAppointment(std::string appointmentID) override;

        std::string getPreviousVisitDate() const;

        void setPreviousVisitDate(std::string newDate);

        const std::vector<Appointment>& getAppointments() const;

    };

}

#endif