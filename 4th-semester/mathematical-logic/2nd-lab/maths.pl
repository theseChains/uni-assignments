approx(N, X, Result) :-
    approxHelper(N, X, pi / 2, Result).

approxHelper(-1, _, Accumulator, Accumulator) :- !.

approxHelper(N, X, Accumulator, Result) :-
    N > -1,
    NewAccumulator is Accumulator + ((-1) ** (N + 1)) / ((2 * N + 1) * X ** (2 * N + 1)),
    DecrementedN is N - 1,
    approxHelper(DecrementedN, X, NewAccumulator, Result).

