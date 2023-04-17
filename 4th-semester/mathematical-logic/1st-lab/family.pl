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

% other information
born(rasim, 1, 1, 2003).
born(aygul, 9, 3, 1977).
born(ramil, 21, 1, 1959).

% complex predicates (rules)
father(X, Y) :- parent(X, Y), male(X).
mother(X, Y) :- parent(X, Y), female(X).
sister(X, Y) :- parent(Z, X), parent(Z, Y), female(X), not(X = Y).
brother(X, Y) :- parent(Z, X), parent(Z, Y), male(X), not(X = Y).
grandfather(X, Y) :- parent(X, Z), parent(Z, Y), male(X).
grandmother(X, Y) :- mother(X, Z), parent(Z, Y).

% is rasim aygul's son?
goal1 :- parent(aygul, rasim), male(rasim).

% is fagim a father?
goal2 :- parent(fagim, _), male(fagim).

% who are the grandchildren of minnur?
goal3 :- (writeln("Minnur's grandchildren are:");
		parent(minnur, X), parent(X, Y), writeln(Y)), fail.

% is razit a grandchild or a son of sonya?
goal4 :- parent(sonya, X), parent(X, razit), writeln("Razit is Sonya's grandson.");
		parent(sonya, razit), writeln("Razit is Sonya's son.").

% who are the children of fagim?
goal5 :- (writeln("Fagim's children are:");
		parent(fagim, X), writeln(X)), fail.

% which people are mothers?
goal6(X) :- mother(X, _), writef("%t is a mother\n", [X]), fail.
