QT5_ADD_RESOURCES(RESOURCE_FILES
    ../../res/darkstyle.qrc
)

add_executable(PolyclinicApp
    ${RESOURCE_FILES}
    Client.cpp
    Client.h
    View/ApplicationViewUi.ui
    View/ApplicationView.cpp
    View/ApplicationView.h
    View/ViewConstants.h
    View/ValidatorSetup.cpp
    View/ValidatorSetup.h
    View/InputValidator.cpp
    View/InputValidator.h
    View/ButtonHandlers/AddSlotDialog.cpp
    View/ButtonHandlers/AddSlotDialog.h
    View/ButtonHandlers/DoctorButtonsHandler.cpp
    View/ButtonHandlers/DoctorButtonsHandler.h
    View/ButtonHandlers/AdministratorButtonsHandler.cpp
    View/ButtonHandlers/AdministratorButtonsHandler.h
    View/ButtonHandlers/RegistratorButtonsHandler.cpp
    View/ButtonHandlers/RegistratorButtonsHandler.h
    View/StackedWidgetNavigator/StackedWidgetNavigator.cpp
    View/StackedWidgetNavigator/StackedWidgetNavigator.h
    main.cpp
)

include_directories(../)

target_link_libraries(PolyclinicApp PRIVATE Qt5::Core Qt5::Network Qt5::Widgets)
