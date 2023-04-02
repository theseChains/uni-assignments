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
