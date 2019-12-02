#!/usr/bin/env python3
from datetime import datetime
from AMPM import to24hour, from12hour, to12hour, from24hour
now = datetime.now()


def test_to24hour():
    time = lambda *t: datetime.time(datetime(now.year, now.month, now.day, *t))
    assert to24hour(time( 2,  2,  2)) == "02:02:02"
    assert to24hour(time(14,  2,  2)) == "14:02:02"
    assert to24hour(time( 7, 57, 28)) == "07:57:28"
    assert to24hour(time(19, 57, 28)) == "19:57:28"
    assert to24hour(time(11, 59, 59)) == "11:59:59"
    assert to24hour(time(23, 59, 59)) == "23:59:59"


def test_to12hour():
    time = lambda *t: datetime.time(datetime(now.year, now.month, now.day, *t))
    assert to12hour(time( 2,  2,  2)) == "02:02:02AM"
    assert to12hour(time(14,  2,  2)) == "02:02:02PM"
    assert to12hour(time( 7, 57, 28)) == "07:57:28AM"
    assert to12hour(time(19, 57, 28)) == "07:57:28PM"
    assert to12hour(time(11, 59, 59)) == "11:59:59AM"
    assert to12hour(time(23, 59, 59)) == "11:59:59PM"


def test_from12hour():
    time = lambda *t: datetime(1900, 1, 1, *t)
    assert from12hour("02:02:02AM") == time( 2,  2,  2)
    assert from12hour("02:02:02PM") == time(14,  2,  2)
    assert from12hour("07:57:28AM") == time( 7, 57, 28)
    assert from12hour("07:57:28PM") == time(19, 57, 28)
    assert from12hour("11:59:59AM") == time(11, 59, 59)
    assert from12hour("11:59:59PM") == time(23, 59, 59)


def test_from24hour():
    time = lambda *t: datetime(1900, 1, 1, *t)
    assert from24hour("02:02:02") == time( 2,  2,  2)
    assert from24hour("14:02:02") == time(14,  2,  2)
    assert from24hour("07:57:28") == time( 7, 57, 28)
    assert from24hour("19:57:28") == time(19, 57, 28)
    assert from24hour("11:59:59") == time(11, 59, 59)
    assert from24hour("23:59:59") == time(23, 59, 59)
