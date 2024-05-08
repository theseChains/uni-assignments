import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.ResultSet;

import java.util.Scanner;

public class HomeLibraryConsoleApp {
    private static final String JDBC_URL = "jdbc:derby://localhost:1527/databases/HomeLibrary;user=db_user;password=db_user";
    private static final String TABLE_BOOK_LOCATION = "BookLocation";
    private static final String TABLE_BOOK_INFO = "BookInfo";

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
                System.out.println("7. Exit");

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
            while (bookInfoResultSet.next()) {
                System.out.println("BookInfo - ID: " + bookInfoResultSet.getInt("id") + ", " +
                        "Author: " + bookInfoResultSet.getString("author_full_name") + ", " +
                        "Title: " + bookInfoResultSet.getString("publication_title") + ", " +
                        "Publisher: " + bookInfoResultSet.getString("publisher") + ", " +
                        "Year of Publication: " + bookInfoResultSet.getInt("year_of_publication") + ", " +
                        "Pages: " + bookInfoResultSet.getInt("number_of_pages") + ", " +
                        "Year of Writing: " + bookInfoResultSet.getInt("year_of_writing") + ", " +
                        "Weight: " + bookInfoResultSet.getInt("weight_in_grams"));
            }
                }

        String bookLocationSql = "SELECT * FROM " + TABLE_BOOK_LOCATION;
        try (Statement bookLocationStatement = connection.createStatement();
                ResultSet bookLocationResultSet = bookLocationStatement.executeQuery(bookLocationSql)) {
            System.out.println("\nAll records from BookLocation:");
            while (bookLocationResultSet.next()) {
                System.out.println("BookLocation - ID: " + bookLocationResultSet.getInt("id") + ", " +
                        "Floor: " + bookLocationResultSet.getInt("floor") + ", " +
                        "Shelf: " + bookLocationResultSet.getInt("shelf") + ", " +
                        "Rack: " + bookLocationResultSet.getInt("rack"));
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
        System.out.print("Enter year of writing: ");
        int yearOfWriting = scanner.nextInt();
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
            bookInfoStatement.setInt(7, yearOfWriting);
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


    private static void updateRecord(Connection connection) throws SQLException {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter ID of the record to update: ");
        int id = scanner.nextInt();
        scanner.nextLine();

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
        System.out.print("Enter ID of the record to delete: ");
        int id = scanner.nextInt();

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
    }

    private static void viewAuthorsOnFloor(Connection connection) throws SQLException {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the floor number: ");
        int floor = scanner.nextInt();

        String sql = "SELECT author_full_name FROM " + TABLE_BOOK_INFO + " INNER JOIN " + TABLE_BOOK_LOCATION +
                     " ON " + TABLE_BOOK_INFO + ".id = " + TABLE_BOOK_LOCATION + ".id WHERE floor = ?";
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
}
