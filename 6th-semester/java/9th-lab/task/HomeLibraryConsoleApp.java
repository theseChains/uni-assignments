import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.ResultSet;
import java.sql.Types;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

import java.util.Scanner;

public class HomeLibraryConsoleApp {
    private static final String JDBC_URL = "jdbc:derby://localhost:1527/databases/HomeLibrary;user=db_user;password=db_user";
    private static final String TABLE_BOOK_LOCATION = "BookLocation";
    private static final String TABLE_BOOK_INFO = "BookInfo";
    private static final String DEFAULT_VALUES_FILE = "default_values.txt";

    public static void main(String[] args) {
        try (Connection connection = DriverManager.getConnection(JDBC_URL)) {
            System.out.println("Connected to the database.");

            Scanner scanner = new Scanner(System.in);

            while (true) {
                System.out.println("\nChoose an option:");
                System.out.println("1. View authors on a specific floor");
                System.out.println("2. View publications with missing year of writing");
                System.out.println("3. View all records");
                System.out.println("4. Add a new record");
                System.out.println("5. Update a record");
                System.out.println("6. Delete a record");
                System.out.println("7. Reset non-key fields");
                System.out.println("8. View all floors");
                System.out.println("9. Exit");

                int choice = scanner.nextInt();
                scanner.nextLine();

                switch (choice) {
                    case 1:
                        viewAuthorsOnFloor(connection);
                        break;
                    case 2:
                        viewPublicationsWithMissingYearOfWriting(connection);
                        break;
                    case 3:
                        viewAllRecords(connection);
                        break;
                    case 4:
                        addNewRecord(connection);
                        break;
                    case 5:
                        updateRecord(connection);
                        break;
                    case 6:
                        deleteRecord(connection);
                        break;
                    case 7:
                        resetNonKeyFields(connection);
                        break;
                    case 8:
                        viewAllFloors(connection);
                        break;
                    case 9:
                        System.out.println("Exiting the application.");
                        return;
                    default:
                        System.out.println("Invalid choice. Please enter a valid option.");
                }
            }
        } catch (SQLException e) {
            System.err.println("Error connecting to the database: " + e.getMessage());
        }
    }

    private static void viewAllRecords(Connection connection) throws SQLException {
        String bookInfoSql = "SELECT * FROM " + TABLE_BOOK_INFO;
        try (Statement bookInfoStatement = connection.createStatement();
                ResultSet bookInfoResultSet = bookInfoStatement.executeQuery(bookInfoSql)) {
            System.out.println("\nAll records from BookInfo:");
            System.out.printf("| %-5s | %-5s | %-15s | %-20s | %-20s | %-15s | %-10s | %-15s | %-10s | %-5s | %-5s | %-5s |\n",
                    "No.", "ID", "Author", "Title", "Publisher", "Year Pub", "Pages", "Year Writing", "Weight", "Floor", "Shelf", "Rack");
            System.out.println("|-------|-------|-----------------|----------------------|----------------------|-----------------|------------|-----------------|------------|-------|-------|-------|");
            printRecords(connection, bookInfoResultSet);
        }
    }

    private static void printRecords(Connection connection, ResultSet bookInfoResultSet) throws SQLException {
        int currentIndex = 1;
        while (bookInfoResultSet.next()) {
            int bookInfoId = bookInfoResultSet.getInt("id");
            String bookLocationSql = "SELECT * FROM " + TABLE_BOOK_LOCATION + " WHERE id = ?";
            try (PreparedStatement bookLocationStatement = connection.prepareStatement(bookLocationSql)) {
                bookLocationStatement.setInt(1, bookInfoId);
                try (ResultSet bookLocationResultSet = bookLocationStatement.executeQuery()) {
                    if (bookLocationResultSet.next()) {
                        int yearOfWriting = bookInfoResultSet.getInt("year_of_writing");
                        String yearOfWritingValue = (bookInfoResultSet.wasNull()) ? "-" : String.valueOf(yearOfWriting);

                        System.out.printf("| %-5d | %-5d | %-15s | %-20s | %-20s | %-15d | %-10d | %-15s | %-10d | %-5d | %-5d | %-5d |\n",
                                currentIndex++,
                                bookInfoId,
                                bookInfoResultSet.getString("author_full_name"),
                                bookInfoResultSet.getString("publication_title"),
                                bookInfoResultSet.getString("publisher"),
                                bookInfoResultSet.getInt("year_of_publication"),
                                bookInfoResultSet.getInt("number_of_pages"),
                                yearOfWritingValue,
                                bookInfoResultSet.getInt("weight_in_grams"),
                                bookLocationResultSet.getInt("floor"),
                                bookLocationResultSet.getInt("shelf"),
                                bookLocationResultSet.getInt("rack"));
                    }
                }
            }
        }
    }

    private static void addNewRecord(Connection connection) throws SQLException {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter author's full name: ");
        String authorFullName = scanner.nextLine();
        System.out.print("Enter publication title: ");
        String publicationTitle = scanner.nextLine();
        System.out.print("Enter publisher: ");
        String publisher = scanner.nextLine();
        System.out.print("Enter year of publication: ");
        int yearOfPublication = scanner.nextInt();
        System.out.print("Enter number of pages: ");
        int numberOfPages = scanner.nextInt();

        System.out.print("Enter year of writing (or leave empty for unknown): ");
        scanner.nextLine();
        String yearOfWritingInput = scanner.nextLine();
        Integer yearOfWriting = null;
        if (!yearOfWritingInput.isEmpty()) {
            yearOfWriting = Integer.parseInt(yearOfWritingInput);
        }

        System.out.print("Enter weight in grams: ");
        int weightInGrams = scanner.nextInt();

        System.out.print("Enter floor number: ");
        int floorNumber = scanner.nextInt();
        System.out.print("Enter shelf number: ");
        int shelfNumber = scanner.nextInt();
        System.out.print("Enter rack number: ");
        int rackNumber = scanner.nextInt();

        int maxBookId = getMaxId(connection, TABLE_BOOK_INFO, "id");
        int maxLocationId = getMaxId(connection, TABLE_BOOK_LOCATION, "id");

        String bookInfoSql = "INSERT INTO " + TABLE_BOOK_INFO +
            " (id, author_full_name, publication_title, publisher, year_of_publication, " +
            "number_of_pages, year_of_writing, weight_in_grams) VALUES (?, ?, ?, ?, ?, ?, ?, ?)";
        try (PreparedStatement bookInfoStatement = connection.prepareStatement(bookInfoSql)) {
            bookInfoStatement.setInt(1, maxBookId + 1);
            bookInfoStatement.setString(2, authorFullName);
            bookInfoStatement.setString(3, publicationTitle);
            bookInfoStatement.setString(4, publisher);
            bookInfoStatement.setInt(5, yearOfPublication);
            bookInfoStatement.setInt(6, numberOfPages);
            if (yearOfWriting != null) {
                bookInfoStatement.setInt(7, yearOfWriting);
            } else {
                bookInfoStatement.setNull(7, Types.INTEGER);
            }
            bookInfoStatement.setInt(8, weightInGrams);
            int rowsInserted = bookInfoStatement.executeUpdate();
            System.out.println(rowsInserted + " record(s) inserted into BookInfo table.");
        }

        String bookLocationSql = "INSERT INTO " + TABLE_BOOK_LOCATION +
            " (id, floor, shelf, rack) VALUES (?, ?, ?, ?)";
        try (PreparedStatement bookLocationStatement = connection.prepareStatement(bookLocationSql)) {
            bookLocationStatement.setInt(1, maxLocationId + 1);
            bookLocationStatement.setInt(2, floorNumber);
            bookLocationStatement.setInt(3, shelfNumber);
            bookLocationStatement.setInt(4, rackNumber);
            int rowsInserted = bookLocationStatement.executeUpdate();
            System.out.println(rowsInserted + " record(s) inserted into BookLocation table.");
        }
    }

    private static int getMaxId(Connection connection, String tableName, String idColumnName) throws SQLException {
        String sql = "SELECT MAX(" + idColumnName + ") FROM " + tableName;
        try (Statement statement = connection.createStatement();
                ResultSet resultSet = statement.executeQuery(sql)) {
            if (resultSet.next()) {
                return resultSet.getInt(1);
            }
        }
        return 0;
    }

    private static int getIdFromLineNumber(Connection connection, int lineNumber) throws SQLException {
        String sql = "SELECT id FROM " + TABLE_BOOK_INFO + " ORDER BY id OFFSET ? ROWS FETCH FIRST 1 ROW ONLY";
        try (PreparedStatement statement = connection.prepareStatement(sql)) {
            statement.setInt(1, lineNumber - 1);
            try (ResultSet resultSet = statement.executeQuery()) {
                if (resultSet.next()) {
                    return resultSet.getInt("id");
                }
            }
        }
        return -1;
    }

    private static void updateRecord(Connection connection) throws SQLException {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter line number of the record to update: ");
        int lineNumber = scanner.nextInt();
        scanner.nextLine();

        int id = getIdFromLineNumber(connection, lineNumber);
        if (id == -1) {
            System.out.println("Record not found for the given line number.");
            return;
        }

        System.out.print("Enter new author's full name: ");
        String authorFullName = scanner.nextLine();
        System.out.print("Enter new publication title: ");
        String publicationTitle = scanner.nextLine();
        System.out.print("Enter new publisher: ");
        String publisher = scanner.nextLine();
        System.out.print("Enter new year of publication: ");
        int yearOfPublication = scanner.nextInt();
        System.out.print("Enter new number of pages: ");
        int numberOfPages = scanner.nextInt();
        System.out.print("Enter new year of writing: ");
        int yearOfWriting = scanner.nextInt();
        System.out.print("Enter new weight in grams: ");
        int weightInGrams = scanner.nextInt();

        System.out.print("Enter new floor number: ");
        int floorNumber = scanner.nextInt();
        System.out.print("Enter new shelf number: ");
        int shelfNumber = scanner.nextInt();
        System.out.print("Enter new rack number: ");
        int rackNumber = scanner.nextInt();

        String bookInfoSql = "UPDATE " + TABLE_BOOK_INFO + " SET author_full_name = ?, " +
            "publication_title = ?, publisher = ?, year_of_publication = ?, " +
            "number_of_pages = ?, year_of_writing = ?, weight_in_grams = ? WHERE id = ?";
        try (PreparedStatement bookInfoStatement = connection.prepareStatement(bookInfoSql)) {
            bookInfoStatement.setString(1, authorFullName);
            bookInfoStatement.setString(2, publicationTitle);
            bookInfoStatement.setString(3, publisher);
            bookInfoStatement.setInt(4, yearOfPublication);
            bookInfoStatement.setInt(5, numberOfPages);
            bookInfoStatement.setInt(6, yearOfWriting);
            bookInfoStatement.setInt(7, weightInGrams);
            bookInfoStatement.setInt(8, id);
            int rowsUpdated = bookInfoStatement.executeUpdate();
            System.out.println(rowsUpdated + " record(s) updated in BookInfo table.");
        }

        String bookLocationSql = "UPDATE " + TABLE_BOOK_LOCATION + " SET floor = ?, " +
            "shelf = ?, rack = ? WHERE id = ?";
        try (PreparedStatement bookLocationStatement = connection.prepareStatement(bookLocationSql)) {
            bookLocationStatement.setInt(1, floorNumber);
            bookLocationStatement.setInt(2, shelfNumber);
            bookLocationStatement.setInt(3, rackNumber);
            bookLocationStatement.setInt(4, id);
            int rowsUpdated = bookLocationStatement.executeUpdate();
            System.out.println(rowsUpdated + " record(s) updated in BookLocation table.");
        }
    }

    private static void deleteRecord(Connection connection) throws SQLException {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter line number of the record to delete: ");
        int lineNumber = scanner.nextInt();

        int id = getIdFromLineNumber(connection, lineNumber);
        if (id == -1) {
            System.out.println("Record not found for the given line number.");
            return;
        }

        connection.setAutoCommit(false);

        try {
            String bookInfoSql = "DELETE FROM " + TABLE_BOOK_INFO + " WHERE id = ?";
            try (PreparedStatement bookInfoStatement = connection.prepareStatement(bookInfoSql)) {
                bookInfoStatement.setInt(1, id);
                int rowsDeletedBookInfo = bookInfoStatement.executeUpdate();
                System.out.println(rowsDeletedBookInfo + " record(s) deleted from BookInfo table.");
            }

            String bookLocationSql = "DELETE FROM " + TABLE_BOOK_LOCATION + " WHERE id = ?";
            try (PreparedStatement bookLocationStatement = connection.prepareStatement(bookLocationSql)) {
                bookLocationStatement.setInt(1, id);
                int rowsDeletedBookLocation = bookLocationStatement.executeUpdate();
                System.out.println(rowsDeletedBookLocation + " record(s) deleted from BookLocation table.");
            }

            connection.commit();
        } catch (SQLException e) {
            System.out.println("Error occurred. Rolling back the transaction.");
            connection.rollback();
        } finally {
            connection.setAutoCommit(true);
        }
    }

    private static void resetNonKeyFields(Connection connection) throws SQLException {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter line number of the record to reset: ");
        int lineNumber = scanner.nextInt();

        int id = getIdFromLineNumber(connection, lineNumber);
        if (id == -1) {
            System.out.println("Record not found for the given line number.");
            return;
        }

        String defaultBookInfoValuesFilePath = "default_book_info_values.txt";
        try (BufferedReader br = new BufferedReader(new FileReader(defaultBookInfoValuesFilePath))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split("=");
                String key = parts[0];
                String value = parts[1];

                String sql = "UPDATE BookInfo SET " + key + " = ? WHERE id = ?";
                try (PreparedStatement statement = connection.prepareStatement(sql)) {
                    statement.setString(1, value);
                    statement.setInt(2, id);
                    int rowsUpdated = statement.executeUpdate();
                    System.out.println(rowsUpdated + " record(s) updated for " + key + " in BookInfo table.");
                } catch (SQLException e) {
                    System.out.println("Error updating " + key + " field in BookInfo table: " + e.getMessage());
                }
            }
        } catch (IOException e) {
            System.out.println("Error reading default values file: " + e.getMessage());
        }

        String defaultBookLocationValuesFilePath = "default_book_location_values.txt";
        try (BufferedReader br = new BufferedReader(new FileReader(defaultBookLocationValuesFilePath))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split("=");
                String key = parts[0];
                String value = parts[1];

                String sql = "UPDATE BookLocation SET " + key + " = ? WHERE id = ?";
                try (PreparedStatement statement = connection.prepareStatement(sql)) {
                    statement.setString(1, value);
                    statement.setInt(2, id);
                    int rowsUpdated = statement.executeUpdate();
                    System.out.println(rowsUpdated + " record(s) updated for " + key + " in BookLocation table.");
                } catch (SQLException e) {
                    System.out.println("Error updating " + key + " field in BookLocation table: " + e.getMessage());
                }
            }
        } catch (IOException e) {
            System.out.println("Error reading default values file: " + e.getMessage());
        }
    }

    private static void viewAuthorsOnFloor(Connection connection) throws SQLException {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the floor number: ");
        int floor = scanner.nextInt();

        String sql = "SELECT author_full_name FROM " + TABLE_BOOK_INFO + " INNER JOIN " + TABLE_BOOK_LOCATION +
                     " ON " + TABLE_BOOK_INFO + ".id = " + TABLE_BOOK_LOCATION + ".id WHERE floor = ? ORDER BY author_full_name";
        try (PreparedStatement statement = connection.prepareStatement(sql)) {
            statement.setInt(1, floor);
            ResultSet resultSet = statement.executeQuery();
            System.out.println("\nAuthors on floor " + floor + ":");
            while (resultSet.next()) {
                System.out.println(resultSet.getString("author_full_name"));
            }
        }
    }

    private static void viewPublicationsWithMissingYearOfWriting(Connection connection) throws SQLException {
        String sql = "SELECT publication_title FROM " + TABLE_BOOK_INFO + " WHERE year_of_writing IS NULL";
        try (Statement statement = connection.createStatement();
             ResultSet resultSet = statement.executeQuery(sql)) {
            System.out.println("\nPublications with missing year of writing:");
            while (resultSet.next()) {
                System.out.println(resultSet.getString("publication_title"));
            }
        }
    }

    private static void viewAllFloors(Connection connection) throws SQLException {
        String sql = "SELECT floor FROM " + TABLE_BOOK_LOCATION + " ORDER BY floor";
        try (Statement statement = connection.createStatement();
            ResultSet resultSet = statement.executeQuery(sql)) {
            System.out.println("\nAll floors in lexicographical order:");
            while (resultSet.next()) {
                System.out.println(resultSet.getInt("floor"));
            }
        }
    }
}
