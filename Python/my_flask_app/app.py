from flask import Flask,request,render_template
app = Flask(__name__)

@app.route('/')
# def hello():
#     return "Hello, Flask!"
def index():
    return render_template('submit.html')

@app.route('/about')
def about():
    return "This is the about page."

@app.route('/greet/<name>')
def greet(name):
    return f"Hello, {name}!"

@app.route('/submit',methods=['POST'])
def submit():
    username=request.form.get('username')
    if not username:
        return 'Please enter your username',400
    return f'Welcome {username}'

if __name__ == '__main__':
    app.run(debug=True)