approx(N, X, Result) :-
    not(number(X)) -> writeln("X should be a number"), fail;
    X =< 1 -> writeln("X should be greater than 1"), fail;
    not(integer(N)) -> writeln("N should be a non-negative integer"), fail;
    N < 0 -> writeln("N should be a non-negative integer"), fail;
    approxHelper(N, X, pi / 2, Result).

approxHelper(-1, _, Accumulator, Accumulator) :- !.

approxHelper(N, X, Accumulator, Result) :-
    NewAccumulator is Accumulator + ((-1) ** (N + 1)) / ((2 * N + 1) * X ** (2 * N + 1)),
    DecrementedN is N - 1,
    approxHelper(DecrementedN, X, NewAccumulator, Result).

precise(X, Result) :-
    not(number(X)) -> writeln("X should be a number"), fail;
    X =< 1 -> writeln("X should be greater than 1"), fail;
    Result is atan(X).

run :-
    write("Enter N: "),
    readln(NList),
    [N | _] = NList,
    write("Enter X: "),
    readln(XList),
    [X | _] = XList,
    precise(X, StandardResult),
    approx(N, X, Result),
    format("standard arctg(~f)    = ~6f\n", [X, StandardResult]),
    format("approximate arctg(~f) = ~6f\n", [X, Result]),
    writef("(N = %d)\n", [N]),
    AbsoluteError is abs(Result - StandardResult),
    format("absolute error = ~6f\n", [AbsoluteError]),
    fail.
