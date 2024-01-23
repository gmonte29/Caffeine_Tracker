
/*Insert new user*/
INSERT INTO User
(UserName, PasswordHash, TagLine)
VALUES
    (@UserName, @PasswordHash, @TagLine)
RETURNING UserID;


/*access specific user based on username/password*/
SELECT UserID
FROM User
where UserName = @UserName
    AND PasswordHash = @PasswordHash
LIMIT 1;

/*update account details for a User*/
UPDATE User
SET UserName = @UserName
    TagLine = @TagLine
WHERE UserID = @UserID
    AND PasswordHash = @PasswordHash
RETURNING UserID;


/*update password*/
Update User
SET PasswordHash = @newPasswordHash
WHERE UserID = @UserID
    AND PasswordHash = @oldPasswordHash
RETURNING UserID;

/*delete user*/
DELETE FROM User
WHERE UserID = @UserID
    AND PasswordHash = @PasswordHash
RETURNING UserID;
