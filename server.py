from flask import Flask, request, jsonify
from flask_cors import CORS

app = Flask(__name__)
CORS(app)


# Route to get sensor data
@app.route('/get_data', methods=['GET'])
def get_sensor_data():
    return jsonify(data)

# Sample data storage (replace this with your actual data handling logic)
data = {"value": 0}

# Route to update sensor data
@app.route('/update_data', methods=['POST'])
def update_data():
    data = request.get_json()

    if "value" in data:
        sensor_data["value"] = data["value"]
        return jsonify({"message": "data updated successfully"})
    else:
        return jsonify({"error": "Invalid request. 'value' missing."}), 400

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)  # Run the API server on all available network interfaces
