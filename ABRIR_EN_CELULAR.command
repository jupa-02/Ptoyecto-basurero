#!/bin/bash
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
IP=$(ipconfig getifaddr en0 || ipconfig getifaddr en1 || echo "localhost")
PORT=8080

echo "========================================================"
echo "    CANECA ROBOT SMARTSORT PRO - SERVIDOR MOVIL"
echo "========================================================"
echo "Servidor activo en tu red Wi-Fi."
echo ""
echo "1. En tu celular (conectado al mismo Wi-Fi de la casa):"
echo "   Escribe en Safari o Chrome: http://$IP:$PORT"
echo ""
echo "2. O escanea el código QR que se abrira en pantalla."
echo "========================================================"
echo "Presiona Ctrl+C en esta ventana cuando quieras cerrar el servidor."

open "http://localhost:$PORT/qr_celular.html"
python3 -m http.server $PORT --directory "$DIR/Simulador_3D_Interactivo"
