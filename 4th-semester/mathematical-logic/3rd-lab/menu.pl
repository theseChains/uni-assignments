% predicate symbols of valence 2 (facts)
parent(aygul, rasim).
parent(ramil, rasim).
parent(fagim, ramil).
parent(fagim, razit).
parent(sonya, ramil).
parent(sonya, razit).
parent(rima, aygul).
parent(minnur, aygul).
parent(rima, alina).
parent(minnur, alina).

% predicate symbols of valence 1 (facts)
male(ramil).
male(fagim).
male(razit).
male(minnur).
male(rasim).

female(aygul).
female(alina).
female(rima).
female(sonya).

% complex predicates (rules)
father(X, Y) :- parent(X, Y), male(X).
mother(X, Y) :- parent(X, Y), female(X).
sister(X, Y) :- parent(Z, X), parent(Z, Y), female(X), not(X = Y).
brother(X, Y) :- parent(Z, X), parent(Z, Y), male(X), not(X = Y).
grandfather(X, Y) :- parent(X, Z), parent(Z, Y), male(X).
grandmother(X, Y) :- mother(X, Z), parent(Z, Y).

% is rasim aygul's son?
goal1 :- parent(aygul, rasim), male(rasim), writeln("true").

% is fagim a father?
goal2 :- parent(fagim, _), male(fagim), writeln("true").

% who are the grandchildren of minnur?
goal3 :- (writeln("Minnur's grandchildren are:");
		parent(minnur, X), parent(X, Y), writeln(Y)), fail.

% is razit a grandchild or a son of sonya?
goal4 :- parent(sonya, X), parent(X, razit), writeln("Razit is Sonya's grandson.");
		parent(sonya, razit), writeln("Razit is Sonya's son.").

% who are the children of fagim?
goal5 :- (writeln("Fagim's children are:");
		parent(fagim, X), writeln(X)), fail.

printFamilyMenu :-
    writeln("choose: "),
    writeln("1 - determine whether rasim is aygul's son: "),
    writeln("2 - determine whether fagim is a father: "),
    writeln("3 - list the grandchildren of minnur: "),
    writeln("4 - determine whether razit is a grandchild or a son of sonya: "),
    writeln("5 - list the children of fagim: "),
    writeln("q - quit from the family menu").

handleFamilyInput([1]) :-
    goal1,
    fail.

handleFamilyInput([2]) :-
    goal2,
    fail.

handleFamilyInput([3]) :-
    goal3,
    fail.

handleFamilyInput([4]) :-
    goal4,
    fail.

handleFamilyInput([5]) :-
    goal5,
    fail.

handleFamilyInput([q]) :-
    !.

runFamily :-
    repeat,
    printFamilyMenu,
    readln(Answer),
    handleFamilyInput(Answer),
    !.

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

runMaths :-
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

printMainMenu :-
	writeln("choose: "),
	writeln("f - family"),
	writeln("m - maths"),
	writeln("e - exit").

handleInput([f]) :-
	runFamily,
    fail.

handleInput([m]) :-
	runMaths,
    fail.

handleInput([e]) :-
	writeln("exiting the main menu").

run :-
	repeat,
	printMainMenu,
	readln(Answer),
	handleInput(Answer),
    !.
