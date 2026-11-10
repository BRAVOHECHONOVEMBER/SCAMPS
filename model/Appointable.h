#ifndef APPOINTABLE_H
#define APPOINTABLE_H

#include <string>

namespace SCAPMS {
    //Declare the Appointment class to avoid circular dependency
    class Appointment;

    class Appointable {

        public:

        // Virtual destructor
        virtual ~Appointable() {}

        // Schedule an appointment
        virtual bool scheduleAppointment(
            const Appointment& appointment
        ) = 0;

        // Cancel an appointment
        virtual bool cancelAppointment(
            std::string appointmentID
        ) = 0;

    };

}

#endif