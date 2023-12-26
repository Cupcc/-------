from openai import OpenAI
import argparse
import json


def request_gpt(args):

    apiUrl = 'https://ssapi.onechat.shop'
    # apiKey = 'sk-j0lQuKMEF3UlB9Hu1e9aAc6d661e47D28b96E7Dd2aFc801b'
    apiKey = 'sk-nvMujcvedYNi8t6VA13f76829cF14a2a84D6F64042B04cB2'
    # openai.api_base = apiUrl
    # openai.api_key = apiKey
    # prompt = "python3 使用request库调用chatgpt api,如何实现stream output in console"
    prompt = args.prompt

    model = args.model

    client = OpenAI(
        api_key=apiKey,
        base_url=apiUrl + '/v1',
    )

    stream = client.chat.completions.create(
        messages=[
            {
                "role": "system",
                "content": ""
            },
            {
                "role": "user",
                "content": prompt
            },
        ],
        model=model,
        stream=True,
        response_format={"type": "json_object"})
    # print(type(stream))
    print(next(stream))
    if stream:
        for chunk in stream:
            if chunk.choices[0].delta.content is not None:
                print(chunk.choices[0].delta.content, end="", flush=True)

    else:
        print("Failed to request.")

    # # write in file
    # with open('data.json', 'w') as f:
    #     json.dump(stream, f)


def parse_arguments():
    # create object
    parser = argparse.ArgumentParser(description='Process arguments.')
    # add arguments
    parser.add_argument(
        '--model',
        '-m',
        type=str,
        default="gpt-4-1106-preview",
        choices=[
            'gpt-4-all', 'gpt-4.5-turbo', 'gpt-3.5-turbo', 'gpt-3.5-1106',
            'gpt-4', 'gpt-4-1106-preview', 'gpt-4-32k'
        ],
        help='The model name.',
    )
    parser.add_argument(
        '--prompt',
        '-p',
        required=True,
        type=str,
        help="Input your prompt.",
    )

    #parse arguments
    args = parser.parse_args()
    return args


def main():
    args = parse_arguments()
    request_gpt(args)


if __name__ == "__main__":
    main()
