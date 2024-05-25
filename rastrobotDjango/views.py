from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework import status

class ESP32DataView(APIView):
    def post(self, request, format=None):
        # Aqui você pode processar os dados recebidos da ESP32
        data = request.data
        # Salvar no banco de dados ou fazer outras operações
        return Response({'message': 'Dados recebidos com sucesso!'}, status=status.HTTP_201_CREATED)
