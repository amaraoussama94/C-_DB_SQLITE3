#include <iostream>
#include<string>
#include<conio.h>
#include <stdlib.h>
#include<conio.h>
#include "sqlite3.h" 

using namespace std;
//global var
sqlite3 *db;
string  sql_d;
char *zErrMsg = 0;
int rc;
char *sql;
////////////////
string Name = "DB-T";
string DB_Name1 = Name + ".db";
const char*  DataBase_Name = DB_Name1.c_str();

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
	int i;
	for (i = 0; i<argc; i++) {
		cout << azColName[i] << "=" << argv[i] ? argv[i] : "NULL";
		cout << "\n";
	}
	cout << "\n";
	_getch();
	return 0;
}


const char* DB_create(string Name, sqlite3 *DB, char *zErrMsg, int rc)
{
	string DB_Name1 = Name + ".db";

	const char*  DB_Name = DB_Name1.c_str();
	rc = sqlite3_open(DB_Name, &DB);
	

	if (rc) {
		cout << "Can't open database: " << sqlite3_errmsg(DB) << endl;
		_getch();
	}
	else {
		cout << "Opened database successfully Creation \n";
		//_getch();
	}
	sqlite3_close(DB);
	return DB_Name;
}

void INSERT_DB(const char* DataBase_Name,sqlite3 *db, char *zErrMsg, int rc, string  sql_d)
{
	string  ID, NAME, AGE, ADRESS, SALARY;
	string app1 = "'";
	string app2 = "'";
	string app3 = "'";

	cout << "give info " << endl;
	

	cout << "\n NAME :";
	cin >> NAME;
	NAME = app1.append(NAME);
	NAME.append(app2);
	cout << "\n AGE : ";
	cin >> AGE;
	cout << "\n ADRESS :";
	cin >> ADRESS;
	ADRESS = app3.append(ADRESS);
	ADRESS.append(app2);
	cout << "\n SALARY : ";
	cin >> SALARY;
	/* Open database */

	rc = sqlite3_open(DataBase_Name, &db);

	if (rc) {
		cout << "Can't open database:" << sqlite3_errmsg(db) << endl;
		_getch();
	}
	else {
		cout << "Opened database successfully\n";
		//_getch();
	}


	/* Create SQL statement */
	sql_d = "INSERT INTO COMPANY (NAME,AGE,ADDRESS,SALARY)      VALUES ("
		
		+ NAME + ","
		+ AGE + ","
		+ ADRESS + ","
		+ SALARY + ");";

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql_d.c_str(), callback, 0, &zErrMsg);

	if (rc != SQLITE_OK) {
		cout << "SQL error:" << zErrMsg << endl;
		sqlite3_free(zErrMsg);
		_getch();
	}
	else {
		cout << "Records created successfully\n";
		_getch();
	}
	sqlite3_close(db);

}

void create_table(const char* DataBase_Name,sqlite3 *db, char *zErrMsg, int rc, char *sql)
{
	/* Open database */
	rc = sqlite3_open(DataBase_Name, &db);

	if (rc) {
		cout << "Can't open database: " << sqlite3_errmsg(db) << endl;
		_getch();
	}
	else {
		cout << "Opened database successfully tab \n";
		//_getch();
	}

	/* Create SQL statement */
	sql = "CREATE TABLE IF NOT EXISTS COMPANY ("   \
		"ID INTEGER PRIMARY KEY AUTOINCREMENT,"\
		"NAME           TEXT    NOT NULL," \
		"AGE            INT     NOT NULL," \
		"ADDRESS        CHAR(50)," \
		"SALARY         REAL );";

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

	if (rc != SQLITE_OK) {
		cout << "SQL error: " << zErrMsg;
		sqlite3_free(zErrMsg);
		_getch();
	}
	else {
		cout << "Table created successfully\n";
		//_getch();
	}
	sqlite3_close(db);
	//_getch();
}


void AFF(const char* DataBase_Name,sqlite3 *db, char *zErrMsg, int rc, char *sql)
{
	int e ;
	cout << "chose" << endl;
	cin >> e;
	if ( e == 1)
	{
		const char  *data = "Callback function called";
		/* Open database */
		rc = sqlite3_open(DataBase_Name, &db);

		if (rc) {
			cout << "Can't open database: " << sqlite3_errmsg(db) << endl;
			_getch();
		}
		else {
			cout << "Opened database successfully\n";
			//_getch();
		}

		/* Create SQL statement */
		sql = "SELECT rowid,* from COMPANY"; 

		/* Execute SQL statement */
		rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

		if (rc != SQLITE_OK) {
			cout << "SQL error: " << zErrMsg << endl;
			sqlite3_free(zErrMsg);
			_getch();
		}
		else {
			cout << "Operation done successfully\n";

		}
		_getch();
		sqlite3_close(db);
	}

	else if (e == 2) 
	{
		const char  *data = "Callback function called";
		/* Open database */
		rc = sqlite3_open(DataBase_Name, &db);

		if (rc) {
			cout << "Can't open database: " << sqlite3_errmsg(db) << endl;
			_getch();
		}
		else {
			cout << "Opened database successfully\n";
			//_getch();
		}

		string name, e="'";
		cout << "give the name to search info :" << endl;
		cin >> name;
		name.append(e);
		name = e.append(name);

		/* Create SQL statement */
		sql_d = "SELECT rowid, * from COMPANY WHERE NAME="+name;

		/* Execute SQL statement */
		rc = sqlite3_exec(db, sql_d.c_str(), callback, (void*)data, &zErrMsg);

		if (rc != SQLITE_OK) {
			cout << "SQL error: " << zErrMsg << endl;
			sqlite3_free(zErrMsg);
			_getch();
		}
		else {
			cout << "Operation done successfully\n";

		}
		_getch();
		sqlite3_close(db);
	}

	else if (e == 3)
	{
		const char  *data = "Callback function called";
		/* Open database */
		rc = sqlite3_open(DataBase_Name, &db);

		if (rc) {
			cout << "Can't open database: " << sqlite3_errmsg(db) << endl;
			_getch();
		}
		else {
			cout << "Opened database successfully\n";
			//_getch();
		}

		/* Create SQL statement */
		string Option;
		cout << "You wanna show all : NAME, AGE , ADDRESS ,SALARY"<< endl;
		cin >> Option;
		sql_d = "SELECT "+Option+" from COMPANY";

		/* Execute SQL statement */
		rc = sqlite3_exec(db, sql_d.c_str(), callback, (void*)data, &zErrMsg);

		if (rc != SQLITE_OK) {
			cout << "SQL error: " << zErrMsg << endl;
			sqlite3_free(zErrMsg);
			_getch();
		}
		else {
			cout << "Operation done successfully\n";

		}
		_getch();
		sqlite3_close(db);
	}
	else  exit(0);
}

void UPDATE_DB(const char* DataBase_Name,sqlite3 *db, char *zErrMsg, int rc, char *sql)
{
	const char  *data = "Callback function called";
	rc = sqlite3_open(DataBase_Name, &db);

	if (rc) {
		cout << "Can't open database: " << sqlite3_errmsg(db) << endl;
		_getch();
	}
	else {
		cout << "Opened database successfully" << endl;
		//_getch();
	}

	string Option, CONT, ID;
	
	cout << "what yo wanna update :\n NAME  AGE  ADDRESS SALARY \n copy the sameelement to change " << endl;
	cin >> Option;
	cout << "enter the new element :" << endl;
	cin >>CONT ;
	cout << "rowid, of  the  Name to change info" << endl;
	cin >> ID;
	if (Option == "AGE"|| Option == "SALARY" )     
	{ 
		/* Create merged SQL statement */
		sql_d = "UPDATE COMPANY set " + Option + " = " + CONT + " where rowid =" + ID + ";"  \
			"SELECT * from COMPANY";

	 }
	else if (Option == "NAME" || Option == "ADDRESS")
	{
		string app1 = "'";
		string app2 = "'";

		CONT.append(app1);
		CONT=app1.append(CONT);
		cout << CONT<<endl;

		/* Create merged SQL statement */
		sql_d = "UPDATE COMPANY set " + Option + " = " + CONT + " where rowid =" + ID + ";"  \
			"SELECT rowid,* from COMPANY";
	}
	

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql_d.c_str(), callback, (void*)data, &zErrMsg);

	if (rc != SQLITE_OK) {
		cout << "SQL error: " << zErrMsg << endl;
		sqlite3_free(zErrMsg);
		_getch();
	}
	else {
		cout << "Operation done successfully\n";
	//	_getch();
	}
	sqlite3_close(db);

}

void DELETE_DB(const char* DataBase_Name,sqlite3 *db, char *zErrMsg, int rc, char *sql )
{

	const char  *data = "Callback function called";

	/* Open database */
	rc = sqlite3_open(DataBase_Name, &db);

	if (rc) {
		cout << "Can't open database: " << sqlite3_errmsg(db) << endl;
		_getch();
	}
	else {
		cout << "Opened database successfully\n";
		//_getch();
	}
	string ID;
	cout << " Eneter the ID of the client you wanna delete" << endl;
	cin >> ID;

	/* Create merged SQL statement */
	sql_d = "DELETE from COMPANY where rowid ="+ID+"; " \
		"SELECT rowid,* from COMPANY";

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql_d.c_str(), callback, (void*)data, &zErrMsg);

	if (rc != SQLITE_OK) {
		cout << "SQL error:" << zErrMsg << endl;
		sqlite3_free(zErrMsg);
		_getch();
	}
	else {
		cout << "Operation done successfully\n";
		// _getch();
	}
	sqlite3_close(db);
}

void chose()
{
	int choose;
	string Name;
	cout << "choose \n -1- INSERT DB  \n -2-AFF  \n -3-UPDATE_DB\n -4- DELETE_DB\n  0-EXIT" ;
	cin >> choose;
	switch (choose)
	{


	case 1:
		INSERT_DB(DataBase_Name, db, zErrMsg, rc, sql_d);
		chose();
		break;
		
	case 2:
		AFF(DataBase_Name, db, zErrMsg, rc, sql);
		chose();
		break;
	
	case 3:
		UPDATE_DB(DataBase_Name, db, zErrMsg, rc, sql);
		chose();
		break;
		
	case 4:
		DELETE_DB(DataBase_Name, db, zErrMsg, rc, sql);
		chose();
		break;
	default:
		exit(0);

	}
}

int main(int argc, char* argv[]) {

	//cout << "give DB name :";
	//cin >> Name;
	//cout << "\n";




	
	//cout << DB_Name1 <<endl;
	
	DB_create(Name, db, zErrMsg, rc);
	
	
	
	create_table(DataBase_Name, db, zErrMsg, rc, sql);
	chose();

}