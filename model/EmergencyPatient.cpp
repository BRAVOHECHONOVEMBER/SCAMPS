#include "EmergencyPatient.h"
#include <iostream>
#include <stdexcept>

using namespace std;

namespace SCAPMS {

    // Constructor
    EmergencyPatient::EmergencyPatient(string id,
                                   string patientName,
                                   int patientAge,
                                   string patientContact,
                                   int urgency)
    : PatientRecord(id, patientName, patientAge, patientContact),
      urgencyLevel(urgency) {

        if (urgencyLevel < 1 || urgencyLevel > 3) {
            throw invalid_argument("Urgency level must be between 1 and 3.");
        }
    }


    // Returns the patient category
    string EmergencyPatient::getPatientType() const {
        return "Emergency Patient";
    }

    // Displays patient information
    void EmergencyPatient::displaySummary() const {

        cout << "\n--- EMERGENCY PATIENT DETAILS ---\n";

        cout << "Patient ID: " << patientID << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Contact: " << contact << endl;
        cout << "Category: " << getPatientType() << endl;
        cout << "Urgency Level: " << urgencyLevel << endl;

        cout << "Total Appointments: " << appointments.size() << endl;
    }

    // Schedules an appointment
    bool EmergencyPatient::scheduleAppointment(
        const Appointment& appointment) {

        if (appointment.getPatientID() != patientID) {
            return false;
        }

        for (const Appointment& existing : appointments) {

            if (existing.getAppointmentID() ==
                appointment.getAppointmentID()) {

                return false;
            }
        }

        appointments.push_back(appointment);

        return true;
    }

    // Cancels an appointment
    bool EmergencyPatient::cancelAppointment(string appointmentID) {

        for (Appointment& appointment : appointments) {

            if (appointment.getAppointmentID() == appointmentID &&
                appointment.getStatus() == "Pending") {

                appointment.cancelAppointment();

                return true;
            }
        }

        return false;
    }

    // Returns the emergency urgency level
    int EmergencyPatient::getUrgencyLevel() const {
        return urgencyLevel;
    }

    // Returns all appointments
    const vector<Appointment>& EmergencyPatient::getAppointments() const {
        return appointments;
    }

}