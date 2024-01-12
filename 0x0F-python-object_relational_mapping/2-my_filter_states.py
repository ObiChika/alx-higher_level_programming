#!/usr/bin/python3
"""
Displays all values in the states table of hbtn_0e_0_usa.
"""

import MySQLdb
import sys

if __name__ == "__main__":
    db = MySQLdb.connect(
        host="localhost",
        user=sys.argv[1],
        passwd=sys.argv[2],
        db=sys.argv[3],
        port=3306
    )

    cur = db.cursor()
    state_name = sys.argv[4]

    cur.execute("SELECT * FROM states WHERE name LIKE BINARY '{}'"
                .format(state_name))

    [print(row) for row in cur.fetchall()]

    cur.close()
    db.close()
