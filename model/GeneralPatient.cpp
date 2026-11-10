#include "GeneralPatient.h"

#include <iostream>

using namespace std;

namespace SCAPMS {

    // Constructor
    GeneralPatient::GeneralPatient(string id, string patientName,
                                int patientAge, string patientContact)
        : PatientRecord(id, patientName, patientAge, patientContact) {
    }

    // Get patient type
    string GeneralPatient::getPatientType() const {
        return "General Patient";
    }

    // Display patient summary
    void GeneralPatient::displaySummary() const {

        cout << "\n--- GENERAL PATIENT DETAILS ---\n";

        cout << "Patient ID: " << patientID << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Contact: " << contact << endl;
        cout << "Category: " << getPatientType() << endl;
        cout << "Total Appointments: " << appointments.size() << endl;
    }

    // Schedule appointment
    bool GeneralPatient::scheduleAppointment(
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

    // Cancel appointment
    bool GeneralPatient::cancelAppointment(string appointmentID) {

        for (Appointment& appointment : appointments) {

            if (appointment.getAppointmentID() == appointmentID &&
                appointment.getStatus() == "Pending") {

                appointment.cancelAppointment();

                return true;
            }
        }

        return false;
    }

    // Retrieve appointments
    const vector<Appointment>& GeneralPatient::getAppointments() const {
        return appointments;
    }

}