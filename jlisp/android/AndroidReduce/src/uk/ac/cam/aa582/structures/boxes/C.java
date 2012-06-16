package uk.ac.cam.aa582.structures.boxes;

/**
 * Contains all the constants used by the boxes to layout themselves, 
 * any field that has the word "factor" at its end defines a constant
 * which is not absolute, but one that needs to be multiplied by the
 * display font size before it can be used.
 * 
 * @author Ahmad Akra
 *
 */
public class C {
	
	/**
	 * The font size you set for formulae is the font used
	 * for the parts of the formulae in display style. The font
	 * size is different for the text, script and scriptscript
	 * styles. <br/><br/> 
	 * This constant is the factor multiplied by the display style
	 * font size to obtain the text style font style
	 */
	public static final float text_font_scale 												= 01.0000f;
	
	/**
	 * The font size you set for formulae is the font used
	 * for the parts of the formulae in display style. The font
	 * size is different for the text, script and scriptscript
	 * styles. <br/><br/> 
	 * This constant is the factor multiplied by the display style
	 * font size to obtain the script style font style
	 */
	public static final float script_font_scale 											= 00.7071f;
	
	/**
	 * The font size you set for formulae is the font used
	 * for the parts of the formulae in display style. The font
	 * size is different for the text, script and scriptscript
	 * styles. <br/><br/> 
	 * This constant is the factor multiplied by the display style
	 * font size to obtain the scriptscript style font style
	 */
	public static final float scriptscript_font_scale 										= 00.5000f;
	
	/**
	 * Letters of the alphabet are usually drawn relative
	 * to their baseline which is a horizontal line y = a
	 * where a is the baseline height. For example the baseline
	 * for letter 'a' only touches it from the bottom, where 'y'
	 * has a tail that goes below its baseline. The axis of the
	 * character is a similar concept except that it has a 
	 * different elevation, for example the axis line cuts approximate
	 * along half the height of letter 'a'. When typesetting formulae
	 * the axis line is used as a reference rather then the baseline.
	 * But conversion between the two is simple because the distance
	 * between them is constant. <br/><br/>
	 * This constant defines the distance between the baseline and 
	 * the axis line.
	 * 
	 */
	public static final float baseline_axis_distance_factor 								= 00.2400f; // multiply by font to get the distance between the expression baseline and the expression axis
	
	/**
	 * This is the default display font size used by a {@link Box} when
	 * {@link Box#setFontSize(float)} is not used
	 */
	public static final float default_font_size 											= 42.0000f;
	
	/**
	 * Nothing is displayed at a smaller font than the one 
	 * specified by this constant. So if you set the display font size
	 * to this minimum value, the font size for the superscripts and subscripts
	 * will not be any smaller.
	 */
	public static final float minimum_font_size 											= 14.0000f; 
	public static final float box_over_box_margin_factor 									= 00.7500f; // multiply this by the font size to get the box-over-box spacing
	public static final float bar_thickness_factor 											= 00.0400f; // multiply by font size to get the thickness of lines (bars, sqrt sign, etc...)

	public static final float minimum_display_sqrt_top_margin_factor 						= 00.3000f;	// multiply by font size to get the minimum margin between the square root bar and the expression underneath
	public static final float minimum_nondisplay_sqrt_top_margin_factor 					= 00.1000f;	// multiply by font size to get the minimum margin between the square root bar and the expression underneath
	public static final float minimum_display_sqrt_bottom_margin_factor 					= 00.0000f;
	public static final float minimum_nondisplay_sqrt_bottom_margin_factor					= 00.0000f;
	public static final float sqrt_bar_nondisplay_thinning_factor							= 00.8000f;
	
	public static final float script_box_right_margin										= 00.0500f;
	public static final float overunder_script_base_margin_factor 							= 00.1000f;
	public static final float base_superscript_margin_factor 								= 00.0500f; // multiply by font size to get the horizontal distance between the base and the superscript
	public static final float superscript_axis_display_elevation_factor						= 00.6500f;
	public static final float superscript_axis_text_elevation_factor						= 00.5525f;
	public static final float superscript_axis_cramped_elevation_factor	 					= 00.4750f;
	public static final float minimum_superscript_elevation_factor 							= 00.1500f; // multiply by font size to get minimum distance between superscript and floor
	public static final float maximum_bracket_shortfall_factor								= 00.1500f; // multiply by font size to get the distance that the inner expression is allowed to peak above/below the brackets
	
	public static final float normal_display_superscriptAxis_baseAxis_distance_factor		= 00.3300f;
	public static final float maximum_display_superscriptFloor_baseAxis_distance_factor		= 00.1000f;
	public static final float maximum_display_superscriptAxis_baseRoof_distance_factor		= 00.1000f;
	public static final float normal_display_subscriptAxis_baseAxis_distance_factor			= 00.3100f;
	public static final float maximum_display_subscriptRoof_baseAxis_distance_factor		= 00.1000f;
	public static final float maximum_display_subscriptAxis_baseFloor_distance_factor		= 00.1000f;
	public static final float minimum_display_subscript_superscript_margin_factor			= 00.1000f;
	
	public static final float normal_text_superscriptAxis_baseAxis_distance_factor			= 00.3725f;
	public static final float maximum_text_superscriptFloor_baseAxis_distance_factor		= 00.1000f;
	public static final float maximum_text_superscriptAxis_baseRoof_distance_factor			= 00.1000f;
	public static final float normal_text_subscriptAxis_baseAxis_distance_factor			= 00.2325f;
	public static final float maximum_text_subscriptRoof_baseAxis_distance_factor			= 00.1000f;
	public static final float maximum_text_subscriptAxis_baseFloor_distance_factor			= 00.1000f;
	public static final float minimum_text_subscript_superscript_margin_factor				= 00.1000f;
	
	public static final float normal_script_superscriptAxis_baseAxis_distance_factor		= normal_text_superscriptAxis_baseAxis_distance_factor;
	public static final float maximum_script_superscriptFloor_baseAxis_distance_factor		= maximum_text_superscriptFloor_baseAxis_distance_factor;
	public static final float maximum_script_superscriptAxis_baseRoof_distance_factor		= maximum_text_superscriptAxis_baseRoof_distance_factor;
	public static final float normal_script_subscriptAxis_baseAxis_distance_factor			= normal_text_subscriptAxis_baseAxis_distance_factor;
	public static final float maximum_script_subscriptRoof_baseAxis_distance_factor			= maximum_text_subscriptRoof_baseAxis_distance_factor;
	public static final float maximum_script_subscriptAxis_baseFloor_distance_factor		= maximum_text_subscriptAxis_baseFloor_distance_factor;
	public static final float minimum_script_subscript_superscript_margin_factor			= minimum_text_subscript_superscript_margin_factor;
	
	public static final float normal_sscript_superscriptAxis_baseAxis_distance_factor		= normal_script_superscriptAxis_baseAxis_distance_factor;
	public static final float maximum_sscript_superscriptFloor_baseAxis_distance_factor		= maximum_script_superscriptFloor_baseAxis_distance_factor;
	public static final float maximum_sscript_superscriptAxis_baseRoof_distance_factor		= maximum_script_superscriptAxis_baseRoof_distance_factor;
	public static final float normal_sscript_subscriptAxis_baseAxis_distance_factor			= normal_script_subscriptAxis_baseAxis_distance_factor;
	public static final float maximum_sscript_subscriptRoof_baseAxis_distance_factor		= maximum_script_subscriptRoof_baseAxis_distance_factor;
	public static final float maximum_sscript_subscriptAxis_baseFloor_distance_factor		= maximum_script_subscriptAxis_baseFloor_distance_factor;
	public static final float minimum_sscript_subscript_superscript_margin_factor			= minimum_script_subscript_superscript_margin_factor;
	
	public static final float normal_cramped_superscriptAxis_baseAxis_distance_factor		= 00.2350f;
	public static final float maximum_cramped_superscriptFloor_baseAxis_distance_factor		= 00.1000f;
	public static final float maximum_cramped_superscriptAxis_baseRoof_distance_factor		= 00.1000f;
	public static final float normal_cramped_subscriptAxis_baseAxis_distance_factor			= 00.3100f;
	public static final float maximum_cramped_subscriptRoof_baseAxis_distance_factor		= 00.1000f;
	public static final float maximum_cramped_subscriptAxis_baseFloor_distance_factor		= 00.1000f;
	public static final float minimum_cramped_subscript_superscript_margin_factor			= 00.1000f;
	
	public static final float fraction_box_left_and_right_margin_factor						= 00.1200f;	
	public static final float numerator_axis_bar_display_margin_factor						= 00.6800f;
	public static final float minimum_numerator_bar_display_margin_factor					= 00.1200f;
	public static final float denominator_axis_bar_display_margin_factor					= 00.6800f;
	public static final float minimum_denominator_bar_display_margin_factor					= 00.1200f;
	public static final float numerator_axis_bar_nondisplay_margin_factor					= 00.1200f;
	public static final float minimum_numerator_bar_nondisplay_margin_factor				= 00.1200f;
	public static final float denominator_axis_bar_nondisplay_margin_factor					= 00.1200f;
	public static final float minimum_denominator_bar_nondisplay_margin_factor				= 00.1200f;
	
	public static final float bracket_inner_box_margin_factor								= 00.0500f;
	public static final float default_space_box_width_factor								= 00.5000f;
	public static final float default_space_box_height_factor								= 00.6200f;
	public static final float default_multiline_box_interbox_margin_factor					= 00.2000f;
	
	public static final float relation_symbol_display_margin_factor							= 00.3000f;
	public static final float relation_symbol_text_margin_factor							= 00.2500f;
	public static final float operation_symbol_margin_factor								= 00.2500f;
	public static final float large_operator_right_margin_factor							= 00.3500f;
	public static final float small_integral_superscript_shift_factor						= -0.0494f;
	public static final float large_integral_superscript_shift_factor						= 00.2083f;
	public static final float small_integral_subscript_shift_factor							= 00.1256f;
	public static final float large_integral_subscript_shift_factor							= 00.6667f;
	public static final float integral_with_limits_right_margin_factor						= 00.2500f;
	public static final float large_sum_and_prod_superscript_shift_factor					= 00.3000f;
	public static final float large_sum_and_prod_subscript_shift_factor						= 00.3000f;
	public static final float small_operator_right_margin_factor 							= 00.1350f;
	
	public static final float abs_bar_piece_height_factor									= 00.1000f;
	public static final float abs_bar_advancing_width_factor 								= 00.1500f;
	
	// The aim is that for example comma_space_width_factor corresponds
	// the space width produced by TeX's "\,"
	public static final float space_space_width_factor 										= 00.3800f;
	public static final float semicolon_space_width_factor									= 00.3000f;
	public static final float colon_space_width_factor										= 00.2700f;
	public static final float comma_space_width_factor 										= 00.2200f;
	public static final float asterisk_space_width_factor 									= 00.1000f;
	public static final float exclamation_space_width_factor								= -0.2000f;
	
	public static final float table_box_inter_row_margin_factor 							= 00.2000f;
	public static final float table_box_inter_column_margin_factor 							= 00.8000f;
}
