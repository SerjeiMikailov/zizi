use rusqlite::{params, Connection};

struct SQLiteManager {
    conn: Connection,
}

impl SQLiteManager {
    fn new(database: &str) -> rusqlite::Result<Self> {
        let conn = Connection::open(database)?;
        Ok(SQLiteManager { conn })
    }

    fn execute_query(&self, query: &str) -> rusqlite::Result<()> {
        self.conn.execute(query, params![])?;
        Ok(())
    }

    fn register_value(&self, value: &str) -> rusqlite::Result<()> {
        let create_table_query = "
            CREATE TABLE IF NOT EXISTS \"Table\" (
                id INTEGER PRIMARY KEY,
                value TEXT
            )
        ";
        self.execute_query(create_table_query)?;

        let insert_query = format!("INSERT INTO \"Table\" (value) VALUES ('{}')", value);
        self.execute_query(&insert_query)?;

        Ok(())
    }

    fn disconnect(&self) {
    }
}

fn main() -> rusqlite::Result<()> {
    let database_name = "db.db";
    let value_to_register = "Hello, SQLite!";

    let sqlite_manager = SQLiteManager::new(database_name)?;
    sqlite_manager.register_value(value_to_register)?;
    Ok(())
}
