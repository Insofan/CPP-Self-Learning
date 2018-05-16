add_executable(ch4
        ch4/main.cpp
        ch4/median.cpp
        ch4/Student.cpp
        ch4/grade.cpp
        )
add_executable(ch5
        ch5/main.cpp
        ch5/median.cpp
        ch5/Student.cpp
        ch5/grade.cpp
        )
add_executable("Fail Extract"
        ch5/failMain.cpp
        ch5/Student.cpp
        ch5/grade.cpp
        ch5/median.cpp
        )
add_executable(spilt
        ch5/spilt/main.cpp
        ch5/spilt/spilt.cpp
        )
add_executable("Frame word"
        "ch5/Frame word/main.cpp"
        "ch5/Frame word/framWord.cpp"
        )
add_executable("algo spilt"
        ch6/spilt/main.cpp
        ch6/spilt/spilt.cpp
        )
add_executable("URL"
        "ch6/URL/main.cpp"

        )
add_executable("Static" ch6/static/main.cpp)
add_executable(map
        ch7/map/main.cpp
        )
add_executable(ch8 ch8/median/main.cpp
        ch8/median/median.h
        )
add_executable(ch8Find
        ch8/find/main.cpp
        )
add_executable(binarySearch ch8/binarySearch/binarySearch.cpp
        "RandomVec/randomVec.cpp"
        )
add_executable(ch9
        ch9/main.cpp
        )

add_executable(ch10
        ch10/test.cpp
        )
add_executable(pointerFunc ch10/pointerFunc.cpp)
add_executable(pointerArray ch10/pointerArray.cpp)
add_executable(main_args ch10/main_args.cpp)
add_executable(new_delete ch10/new_delete.cpp)

add_executable(OOP ch13/Core.cpp
        ch13/Grad.cpp
        )