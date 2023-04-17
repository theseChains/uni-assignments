approx(N, X, Result) :-
    N >= 0, X > 1, integer(N),
    approxHelper(N, X, pi / 2, Result).

% input validity checks
approx(N, _, _) :-
    N < 0,
    writeln("N should be non-negative").

approx(N, _, _) :-
    not(integer(N)),
    writeln("N should be an integer").

approx(_, X, _) :-
    X =< 1,
    writeln("X should be greater than 1").

approxHelper(-1, _, Accumulator, Accumulator) :- !.

approxHelper(N, X, Accumulator, Result) :-
    N > -1,
    NewAccumulator is Accumulator + ((-1) ** (N + 1)) / ((2 * N + 1) * X ** (2 * N + 1)),
    DecrementedN is N - 1,
    approxHelper(DecrementedN, X, NewAccumulator, Result).

run :-
    repeat,
    menu,
    readln(Option),
    handle(Option).

menu :-
    nl,
    writeln("choose:"),
    writeln("calculate - calculate absolute error for arctg(X)"),
    writeln("exit - terminate").

handle([calculate]) :-
    write("Enter N: "),
    readln(NList),
    [N | _] = NList,
    write("Enter X: "),
    readln(XList),
    [X | _] = XList,
    StandardResult is atan(X),
    format("standard arctg(~d)    = ~6f\n", [X, StandardResult]),
    approx(N, X, Result),
    format("approximate arctg(~d) = ~6f\n", [X, Result]),
    writef("(N = %d)\n", [N]),
    AbsoluteError is abs(Result - StandardResult),
    format("absolute error = ~6f\n", [AbsoluteError]),
    fail.

handle([exit]) :-
    writeln("exiting the run loop").
