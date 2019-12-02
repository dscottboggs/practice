
def register(method, path):
    def rval(self, fun):
        return self.actions[method][path]
    return rval


class API:
    def __init__(self):
        self.actions = {'GET': {}, 'POST': {}}

    def get(self, url, payload=None):
        action = self.actions['GET'].get(url)
        if action:
            return action(payload)

    def post(self, url, payload=None):
        action = self.actions['POST'].get(url)
        if action:
            return action(payload)


class RestAPI(API):
    def __init__(self, database=None):
        self.database = database or {"users": []}
        super()

    @register('GET', "/users")
    def get_users(self, payload):
        payload = payload or {}
        selected_users = payload.get('users') or \
            list(filter(bool, [payload.get('user')])) or \
            self.database['users'].keys()
        return {
            "users": [
                user for user
                in self.database['users']
                if user in selected_users
            ]
        }

    @register('POST', '/add')
    def add_user(self, payload):
        uname = payload['user']
        if self.database[uname]:
            raise Exception("user named %s already exists" % uname)
        user = {
            'name': uname,
            'owes': {},
            'owed_by': {},
            'balance': float(0)
        }
        self.database[uname] = user
        return user

    @register('POST', '/iou')
    def add_debt(self, payload):
        lender_n = payload['lender']
        borrower_n = payload['borrower']
        amount = payload['amount']
        lender = self.database.get(lender_n, self.add_user({"user": lender_n}))
        borrower = self.database.get(
            borrower_n, self.add_user({"user": borrower_n}))
        owes = lender['owes']
        owes[borrower_n] = owes.get(borrower_n, 0) + amount
        lender['owes'] = owes
        owed = borrower['owed_by']
        owed[lender_n] = owed.get(lender_n, 0) + amount
        return {
            'users': [
                user for user in self.database if user['name'] in (lender_n, borrower_n)
            ]
        }
