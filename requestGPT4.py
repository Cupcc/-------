import requests
import json

# apiUrl = ' https://chatapi.onechat.fun/v1/chat/completions'

# apiKey = 'sk-6yJ5qOik53kgvuEU87Ba522aEe134a95962f4b171a55273f'
apiUrl = 'https://ssapi.onechat.shop/v1/chat/completions'
apiKey = 'sk-j0lQuKMEF3UlB9Hu1e9aAc6d661e47D28b96E7Dd2aFc801b'
temperature = 1.0
max_tokens = 600
model = 'gpt-4'

headers = {
    'Accept': 'application/json',
    'Content-Type': 'application/json',
    'Authorization': 'Bearer ' + apiKey
}

post = {
    'model': model,
    'max_tokens': max_tokens,
    'temperature': temperature,
    'messages': [
        {
            'role': 'system',
            'content': 'You act as an embedded expert to assist me to complete software development. providing detailed and specific solutions, examples and explanations.'
        },
        {
            'role': 'user',
            'content': '使用python3 请求gpt-4 api，如何实现流式输出？'
        }
    ]
}


try:
    response = requests.post(
        apiUrl,
        headers=headers,
        data=json.dumps(post),
        stream = True,
        timeout=None
    )
    print(f"Response status code: {response.status_code}")

    if response.status_code == 200:
        if response.text:
            print (response.json())
            # for chunk in response.json():
            #     print(chunk)
            #     # if chunk:
                #     print(chunk.choices[0].delta)
        else:
            print("The response is empty.")
    else:
        print(f"Request failed, response content: {response.text}")
except Exception as e:
    print('Error:', e)
    