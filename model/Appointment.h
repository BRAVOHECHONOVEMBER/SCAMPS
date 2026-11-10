#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>

namespace SCAPMS {

    class Appointment {

        private:

        std::string appointmentID;
        std::string patientID;
        std::string appointmentDate;
        std::string appointmentTime;            
        std::string reason;
        std::string status;
    

        public:

        // Constructor
        Appointment(std::string id, std::string pID,
                std::string date, std::string time,
                std::string appointmentReason);

        // Getters
        std::string getAppointmentID() const;
        std::string getPatientID() const;
        std::string getAppointmentDate() const;
        std::string getAppointmentTime() const;
        std::string getReason() const;
        std::string getStatus() const;

        // Setters
        void setAppointmentDate(std::string newDate);
        void setAppointmentTime(std::string newTime);
        void setReason(std::string newReason);

        // Appointment operations
        void cancelAppointment();
        void completeAppointment();

    };

}

#endif