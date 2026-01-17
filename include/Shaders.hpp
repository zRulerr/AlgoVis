const char* sdfShaderCode = 
    "#version 330\n"
    "in vec2 fragTexCoord;\n"
    "in vec4 fragColor;\n"
    "out vec4 finalColor;\n"
    "uniform sampler2D texture0;\n"
    "void main() {\n"
    "    float distance = texture(texture0, fragTexCoord).r;\n"
    "    // Standard-SDF Berechnung\n"
    "    float alpha = smoothstep(0.4, 0.6, distance);\n" 
    "    finalColor = vec4(fragColor.rgb, fragColor.a * alpha);\n"
    "}\n";