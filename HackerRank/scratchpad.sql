CREATE TABLE celebs (
	id INTEGER,
  name TEXT,
  age INTEGER
);

INSERT INTO celebs (id, name, age)
	VALUES (1, "Justin Beiber", 21);

INSERT INTO celebs (id, name, age)
	VALUES (2, 'Beyonce Knowles', 33);
INSERT INTO celebs (id, name, age)
	VALUES (3, 'Jeremy Lin', 26);
INSERT INTO celebs (id, name, age)
	VALUES (4, 'Taylor Swift', 26);

UPDATE 	celebs
	SET		age=22
  WHERE id=1;

ALTER TABLE celebs ADD COLUMN twitter_handle TEXT;

UPDATE 	celebs
	SET 	twitter_handle 	= "@taylorswift13"
	WHERE id							= 4;
DELETE FROM celebs WHERE twitter_handle IS NULL;

CREATE TABLE awards (
	id INTEGER PRIMARY KEY,
	recipient TEXT NOT NULL,
	award_name TEXT DEFAULT "Grammy"
);