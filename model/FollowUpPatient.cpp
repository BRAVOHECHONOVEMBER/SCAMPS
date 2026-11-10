#include "FollowUpPatient.h"
#include <iostream>

using namespace std;

namespace SCAPMS {

    // Constructor
    FollowUpPatient::FollowUpPatient(string id, string patientName,
                                 int patientAge, string patientContact,
                                 string lastVisitDate)
    : PatientRecord(id, patientName, patientAge, patientContact),
      previousVisitDate(lastVisitDate) {
    }

    // Get patient type
    string FollowUpPatient::getPatientType() const {
        return "Follow-Up Patient";
    }

    // Display patient details
    void FollowUpPatient::displaySummary() const {

        cout << "\n--- FOLLOW-UP PATIENT DETAILS ---\n";

        cout << "Patient ID: " << patientID << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Contact: " << contact << endl;
        cout << "Category: " << getPatientType() << endl;
        cout << "Previous Visit Date: " << previousVisitDate << endl;
        cout << "Total Appointments: " << appointments.size() << endl;
    }

    // Schedule appointment
    bool FollowUpPatient::scheduleAppointment(const Appointment& appointment) {

        if (appointment.getPatientID() != patientID) {
            return false;
        }

        for (const Appointment& existing : appointments) {

            if (existing.getAppointmentID() == appointment.getAppointmentID()) {
                return false;
            }
        }

        appointments.push_back(appointment);
        return true;
    }

    // Cancel appointment
    bool FollowUpPatient::cancelAppointment(string appointmentID) {

        for (Appointment& appointment : appointments) {

            if (appointment.getAppointmentID() == appointmentID &&
                appointment.getStatus() == "Pending") {

                appointment.cancelAppointment();
                return true;
            }
        }

        return false;
    }

    // Get previous visit date
    string FollowUpPatient::getPreviousVisitDate() const {
        return previousVisitDate;
    }

    // Update previous visit date
    void FollowUpPatient::setPreviousVisitDate(string newDate) {
        previousVisitDate = newDate;
    }

    // Get appointments
    const vector<Appointment>& FollowUpPatient::getAppointments() const {
        return appointments;
    }

}