import json
import models
from models import Department
from django.contrib.auth.models import User


def savePerson():
    with open("Person.json") as file:
        person = json.load(file)

        for x in person:
            print(x)

            r = models.Person(first_name=x["first_name"],
                              last_name=x["last_name"],
                              card_number=x["card_number"],
                              email_address=x["email_address"],
                              phone_number=x["phone_number"],
                              date_of_create=x["date_of_create"],
                              position=x["position"],
                              department=x["department_id"] - 1,
                              user=x["user_id"],
                              is_active=x["is_active"],
                              date_of_archieve=x["date_of_archive"],
                              old_id=x["id"])
            r.save


def saveDep():
    with open("Departments.json") as sfile:
        department = json.load(sfile)

        for x in department:
            print(x)

            r = Department(department=x["department"],
                           restriction=x["restriction"],
                           old_id=x["id"])

            r.save


def saveUser():
    with open("user.json") as file:
        users = json.load(file)

        for x in users:

            user = User.objects.create_user(username=x["username"], email=x["email"], password=x["password"])
            user.is_staff = x["is_staff"]
            user.first_name = x["first_name"]
            user.last_name = x["last_name"]
            user.is_active = x["is_active"]
            user.is_superuser = x["is_superuser"]
            user.last_login = x["last_login"]
            user.date_joined = x["date_joined"]
            user.id = x["id"]

            user.save()


def saveCE():
    dane = []
    with open("CalendarEvents.JSON") as file:
        calendarevent = json.load(file)
        event_iterator = iter(calendarevent)
        for row in reversed(calendarevent):

            start = row
            end = row
            nrow = next(event_iterator)

            while nrow["person_id"] == row["person_id"] and nrow["event_type"] == row["event_type"]:
                end = next(event_iterator)

            # CE = CalendarEvent(person=row["person_id"],event_type=row["event_type"],comment=row["comment"],
            # old_id=row["id"],start_date=start,end_date=end) CE.save()

            CE = {'person': row['person_id'],
                  'event_type': row['event_type'],
                  'comment': row['comment'],
                  'old_id': row['id'],
                  'start_date': start['date_of_event'],
                  'end_date': end['date_of_event']}

            dane.append(CE)
    print(dane)


saveUser()
