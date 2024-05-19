add_executable(PolyclinicServer
    Server.cpp
    Server.h
    DatabaseHandler/DatabaseHandler.cpp
    DatabaseHandler/DatabaseHandler.h
    ClientHandler/ClientHandler.cpp
    ClientHandler/ClientHandler.h
    main.cpp
)

include_directories(../)

target_link_libraries(PolyclinicServer PRIVATE Qt5::Core Qt5::Network Qt5::Sql)
