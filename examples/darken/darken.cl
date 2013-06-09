__constant const sampler_t g_sampler =
        CLK_FILTER_NEAREST|CLK_NORMALIZED_COORDS_FALSE|CLK_ADDRESS_CLAMP_TO_EDGE;

__kernel void darken_image(__read_only image2d_t input_image, __write_only image2d_t output_image)
{
    int2 coord = (int2)( get_global_id(0), get_global_id(1) );

    float4 val = read_imagef (input_image, g_sampler, coord) / 2;

    write_imagef (output_image, coord, val);
}
